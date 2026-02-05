# PowerShell script for parallel incremental compilation with timing
# Supports Debug/Release configurations and keeps outputs separated:
#   build\Debug\...
#   build\Release\...
#
# Incremental dependency tracking:
#   Uses `cl.exe /showIncludes` to capture header dependencies per translation unit.
#   Saves them under: build\<Config>\obj\deps\<name>.deps.txt
#   Rebuilds a TU if any listed header is newer than the corresponding .obj.
#
# Performance notes:
#   - We DO NOT print the noisy "/showIncludes" lines to the console (it is very slow).
#   - We store only project-local headers (under $PSScriptRoot) as dependencies.
#     System headers almost never change and checking them would be expensive.
#   - We skip the link step if nothing was recompiled.
#   - We regenerate compile_commands.json only when sources have changed since last gen.

param(
    # Base build directory (config subdirs will be created under it)
    [string]$BuildDir = (Join-Path $PSScriptRoot "build"),

    # Build configuration
    [ValidateSet("Debug", "Release")]
    [string]$Config = "Debug"
)

$ProjectRoot = (Resolve-Path -LiteralPath $PSScriptRoot).Path

$vcvars64  = "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Auxiliary\\Build\\vcvars64.bat"
$vscodeDir = Join-Path $PSScriptRoot ".vscode"   # only cache/config, not build outputs
$cppFiles  = Get-ChildItem -Path $PSScriptRoot -Filter "*.cpp"

# Resolve BuildDir (relative -> under project root)
if (![System.IO.Path]::IsPathRooted($BuildDir)) {
    $BuildDir = Join-Path $PSScriptRoot $BuildDir
}

# Ensure directories exist
if (!(Test-Path $vscodeDir)) { New-Item -ItemType Directory -Path $vscodeDir | Out-Null }
if (!(Test-Path $BuildDir))  { New-Item -ItemType Directory -Path $BuildDir  | Out-Null }

# Normalize BuildDir to an absolute path
$BuildDir = (Resolve-Path -LiteralPath $BuildDir).Path

# Config-specific build root
$ConfigBuildDir = Join-Path $BuildDir $Config
if (!(Test-Path $ConfigBuildDir)) { New-Item -ItemType Directory -Path $ConfigBuildDir | Out-Null }

$ObjDir = Join-Path $ConfigBuildDir "obj"
if (!(Test-Path $ObjDir)) { New-Item -ItemType Directory -Path $ObjDir | Out-Null }

# Per-TU dependency files (one per .cpp)
$DepDir = Join-Path $ObjDir "deps"
if (!(Test-Path $DepDir)) { New-Item -ItemType Directory -Path $DepDir | Out-Null }

# Detect the number of logical processors
$maxParallel = [System.Environment]::ProcessorCount
$jobs       = @()
$objFiles   = @()

# Track whether we actually compiled anything in this run
$compiledAny = $false

# Start timing
$startTime = [System.Diagnostics.Stopwatch]::StartNew()

# vcvars environment cache path
$vcvarsCache = Join-Path $vscodeDir "vcvars_env.ps1"

# Generate and cache vcvars environment if missing
if (!(Test-Path $vcvarsCache)) {
    Write-Host "Generating vcvars environment cache..."
    cmd.exe /c "set" >  (Join-Path $vscodeDir "before_vcvars.txt")
    cmd.exe /c "call `"$vcvars64`" && set" > (Join-Path $vscodeDir "after_vcvars.txt")

    Compare-Object `
      (Get-Content (Join-Path $vscodeDir "before_vcvars.txt")) `
      (Get-Content (Join-Path $vscodeDir "after_vcvars.txt")) |
      Where-Object { $_.SideIndicator -eq '=>' } |
      ForEach-Object {
          if ($_.InputObject -match "^(.*?)=(.*)$") {
              "Set-Item -Path env:$($matches[1]) -Value `"$($matches[2])`""
          }
      } | Out-File -Encoding ASCII $vcvarsCache

    Remove-Item `
      (Join-Path $vscodeDir "before_vcvars.txt"), `
      (Join-Path $vscodeDir "after_vcvars.txt")
}

# Load cached vcvars environment
Write-Host "Loading cached vcvars environment..."
. $vcvarsCache

# Shared compiler PDB per config (so /Zi does not spill vc*.pdb into the project root)
$compilerPdb = Join-Path $ConfigBuildDir "vc_compile.pdb"

# --- Determine flags per configuration ---
$commonFlags = @(
    '/std:c++20',
    '/EHsc',
    '/nologo',
    '/FS',
    '/W4',
    '/permissive-',
    '/external:anglebrackets',
    '/external:W0'
)

# Debug vs Release flags
if ($Config -eq "Debug") {
    $configFlags = @(
        '/Od',
        '/Zi',
        '/MDd',
        '/D_DEBUG'
    )
    $linkExtraFlags = @(
        '/DEBUG',
        '/INCREMENTAL'
    )
} else {
    $configFlags = @(
        '/O2',
        '/Zi',
        '/MD',
        '/DNDEBUG'
    )
    $linkExtraFlags = @(
        '/DEBUG',
        '/INCREMENTAL:NO',
        '/OPT:REF',
        '/OPT:ICF'
    )
}

# --- Include/define flags (explicit, so we don't rely on environment magic) ---
$includeFlags = @()
if ($env:INCLUDE) {
    $includeFlags = $env:INCLUDE.Split(';') |
        Where-Object { $_ -and $_.Trim().Length -gt 0 } |
        ForEach-Object { '/I"{0}"' -f $_ }
}
$defineFlags = @()

# --- Generate compile_commands.json for IntelliSense (MSVC), only when needed ---
$compileCommandsPath   = Join-Path $ConfigBuildDir "compile_commands.json"
$compileCommandsLatest = Join-Path $BuildDir "compile_commands.json"

$needCompileDb = $false
if (!(Test-Path $compileCommandsPath)) {
    $needCompileDb = $true
} else {
    $ccTime = (Get-Item $compileCommandsPath).LastWriteTime
    if (($cppFiles | Where-Object { $_.LastWriteTime -gt $ccTime }).Count -gt 0) {
        $needCompileDb = $true
    }
    # If build.ps1 itself changed, the commands/flags might have changed too.
    if ((Get-Item $MyInvocation.MyCommand.Path).LastWriteTime -gt $ccTime) {
        $needCompileDb = $true
    }
}

if ($needCompileDb) {
    # Absolute path to cl.exe (after vcvars is loaded, it should be resolvable)
    $clPath = (Get-Command cl.exe).Source

    $compileDb = @()
    foreach ($file in $cppFiles) {
        $objFile = Join-Path $ObjDir ([System.IO.Path]::GetFileNameWithoutExtension($file.Name) + ".obj")

        $cmdParts = @(
            ('"{0}"' -f $clPath)
        ) + $commonFlags + $configFlags + @(
            ('/Fd"{0}"' -f $compilerPdb),
            '/c',
            ('/Fo"{0}"' -f $objFile)
        ) + $includeFlags + $defineFlags + @(
            ('"{0}"' -f $file.FullName)
        )

        $compileDb += [PSCustomObject]@{
            directory = $PSScriptRoot
            command   = ($cmdParts -join ' ')
            file      = $file.FullName
            output    = $objFile
        }
    }

    # Write JSON as UTF-8 without BOM (cpptools/clangd both handle this well)
    $json = ($compileDb | ConvertTo-Json -Depth 6)
    $utf8NoBom = New-Object System.Text.UTF8Encoding($false)
    [System.IO.File]::WriteAllText($compileCommandsPath, $json, $utf8NoBom)

    # Keep a stable "latest" path for VSCode settings
    Copy-Item -LiteralPath $compileCommandsPath -Destination $compileCommandsLatest -Force

    Write-Host "Generated compile_commands.json at: $compileCommandsPath"
    Write-Host "Updated IDE compile_commands.json at: $compileCommandsLatest"
} else {
    Write-Host "compile_commands.json is up-to-date."
}

# ---------------------------------------------------------------------------
# Dependency tracking helpers
# ---------------------------------------------------------------------------

function Test-NeedsRebuild {
    param(
        [System.IO.FileInfo]$CppFile,
        [string]$ObjFile,
        [string]$DepFile
    )

    if (!(Test-Path $ObjFile)) { return $true }

    $objTime = (Get-Item $ObjFile).LastWriteTime
    if ($CppFile.LastWriteTime -gt $objTime) { return $true }

    # If we don't have deps yet, do one compile to generate them.
    if (!(Test-Path $DepFile)) { return $true }

    $deps = Get-Content -LiteralPath $DepFile -ErrorAction SilentlyContinue
    foreach ($d in $deps) {
        if ($d -and (Test-Path $d)) {
            if ((Get-Item $d).LastWriteTime -gt $objTime) { return $true }
        }
    }

    return $false
}

# Compile only changed .cpp files in parallel
foreach ($file in $cppFiles) {
    $baseName = [System.IO.Path]::GetFileNameWithoutExtension($file.Name)
    $objFile  = Join-Path $ObjDir  ($baseName + ".obj")
    $depFile  = Join-Path $DepDir  ($baseName + ".deps.txt")

    if (Test-NeedsRebuild -CppFile $file -ObjFile $objFile -DepFile $depFile) {

        $compiledAny = $true

        $job = Start-Job -ScriptBlock {
            param ($file, $objFile, $depFile, $compilerPdb, $commonFlags, $configFlags, $includeFlags, $defineFlags, $projectRoot)

            # Compile with /showIncludes so we can persist header dependencies for next builds.
            # We intentionally do NOT print the noisy include lines to the console.
            $flags = @(
                $commonFlags + $configFlags + @(
                    ('/Fd"{0}"' -f $compilerPdb),
                    '/showIncludes',
                    '/c',
                    ('/Fo"{0}"' -f $objFile),
                    ('"{0}"' -f $file.FullName)
                ) + $includeFlags + $defineFlags
            ) -join ' '

            $output = cmd.exe /c ("cl.exe " + $flags + " 2>&1")

            # If compilation failed, print everything and fail the job.
            if ($LASTEXITCODE -ne 0) {
                $output | ForEach-Object { Write-Host $_ }
                exit $LASTEXITCODE
            }

            # Parse /showIncludes output and persist dependencies.
            # We store ONLY project-local headers (under $projectRoot). System headers are excluded.
            $deps = New-Object System.Collections.Generic.HashSet[string] ([StringComparer]::OrdinalIgnoreCase)

            foreach ($line in $output) {
                # Example (EN): "Note: including file:  C:\path\to\header.h"
                # Example (PL): "Uwaga: uwzględniono plik:  C:\path\to\header.h"
                if ($line -match '^(?:Note|Uwaga)\s*:\s*(?:including file|uwzględniono plik)\s*:\s*(.+)$') {
                    $p = $matches[1].Trim()
                    if ($p) {
                        try {
                            $resolved = (Resolve-Path -LiteralPath $p -ErrorAction Stop).Path
                            if ($resolved.StartsWith($projectRoot, [System.StringComparison]::OrdinalIgnoreCase)) {
                                [void]$deps.Add($resolved)
                            }
                        } catch {
                            # Ignore unresolvable paths; they are almost always system headers.
                        }
                    }
                } else {
                    # Print non-include lines only (errors/warnings/normal output).
                    if ($line -and ($line.Trim().Length -gt 0)) {
                        Write-Host $line
                    }
                }
            }

            # Write one dependency per line (ASCII is enough for Windows paths).
            Set-Content -LiteralPath $depFile -Value ($deps | Sort-Object) -Encoding ASCII

        } -ArgumentList $file, $objFile, $depFile, $compilerPdb, $commonFlags, $configFlags, $includeFlags, $defineFlags, $projectRoot

        $jobs += $job
    } else {
        Write-Host "Skipping $($file.Name), up-to-date."
    }

    $objFiles += $objFile

    # Limit the number of concurrent jobs to avoid CPU overload
    if ($jobs.Count -ge $maxParallel) {
        foreach ($j in $jobs) {
            Receive-Job -Job $j -Wait
            Remove-Job -Id $j.Id
        }
        $jobs = @()
    }
}

# Wait for any remaining compilation jobs to finish
if ($jobs.Count -gt 0) {
    Write-Host "Waiting for compilation jobs to finish..."
    foreach ($j in $jobs) {
        Receive-Job -Job $j -Wait
        Remove-Job -Id $j.Id
    }
}

# Linking step (skip if nothing was recompiled)
$exeOut  = Join-Path $ConfigBuildDir "TestsRunner.exe"
if ($compiledAny -or !(Test-Path $exeOut)) {
    Write-Host "Linking executable (via response file)..."

    $linkRsp = Join-Path $ConfigBuildDir "link.rsp"
    $pdbOut  = Join-Path $ConfigBuildDir "TestsRunner.pdb"
    $ilkOut  = Join-Path $ConfigBuildDir "TestsRunner.ilk"

    # Build RSP contents: each .obj on a separate line + linker options
    $lines = @()
    $lines += ($objFiles | ForEach-Object { '"{0}"' -f $_ })
    $lines += $linkExtraFlags
    $lines += ('/OUT:"{0}"' -f $exeOut)
    $lines += ('/PDB:"{0}"' -f $pdbOut)
    $lines += ('/ILK:"{0}"' -f $ilkOut)
    $lines += '/LTCG:OFF'

    # Important: use ASCII, NOT the default UTF-16
    Set-Content -Path $linkRsp -Value ($lines -join [Environment]::NewLine) -Encoding ASCII

    # Run the linker with the RSP
    cmd.exe /c "link.exe /nologo @`"$linkRsp`""
} else {
    Write-Host "Link step skipped (no compilation, executable already exists)."
}

# Stop timing
$endTime = $startTime.Elapsed
Write-Host "$Config build completed in $($endTime.TotalMilliseconds) ms."
Write-Host "Output: $exeOut"
