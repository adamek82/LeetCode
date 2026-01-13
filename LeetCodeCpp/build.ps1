# PowerShell script for parallel incremental compilation with timing
# Supports Debug/Release configurations and keeps outputs separated:
#   build\Debug\...
#   build\Release\...

param(
    # Base build directory (config subdirs will be created under it)
    [string]$BuildDir = (Join-Path $PSScriptRoot "build"),

    # Build configuration
    [ValidateSet("Debug", "Release")]
    [string]$Config = "Debug"
)

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

# Detect the number of logical processors
$maxParallel = [System.Environment]::ProcessorCount
$jobs       = @()
$objFiles   = @()

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
    '/FS'
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

# --- Generate compile_commands.json for IntelliSense (MSVC) ---

# Absolute path to cl.exe (after vcvars is loaded, it should be resolvable)
$clPath = (Get-Command cl.exe).Source

# Convert INCLUDE env var to explicit /I flags so IntelliSense doesn't rely on environment magic
$includeFlags = @()
if ($env:INCLUDE) {
    $includeFlags = $env:INCLUDE.Split(';') |
        Where-Object { $_ -and $_.Trim().Length -gt 0 } |
        ForEach-Object { '/I"{0}"' -f $_ }
}

# (Optional) If you use preprocessor defines globally, you can also emit /D flags here.
$defineFlags = @()

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

    $command = ($cmdParts -join ' ')

    $compileDb += [PSCustomObject]@{
        directory = $PSScriptRoot
        command   = $command
        file      = $file.FullName
        output    = $objFile
    }
}

# Write JSON as UTF-8 without BOM (cpptools/clangd both handle this well)
$compileCommandsPath = Join-Path $ConfigBuildDir "compile_commands.json"
$json = ($compileDb | ConvertTo-Json -Depth 6)

$utf8NoBom = New-Object System.Text.UTF8Encoding($false)
[System.IO.File]::WriteAllText($compileCommandsPath, $json, $utf8NoBom)

# Also keep a stable "latest" path for VSCode settings
$compileCommandsLatest = Join-Path $BuildDir "compile_commands.json"
Copy-Item -LiteralPath $compileCommandsPath -Destination $compileCommandsLatest -Force

Write-Host "Generated compile_commands.json at: $compileCommandsPath"
Write-Host "Updated IDE compile_commands.json at: $compileCommandsLatest"

# Compile only changed .cpp files in parallel
foreach ($file in $cppFiles) {
    $objFile = Join-Path $ObjDir ([System.IO.Path]::GetFileNameWithoutExtension($file.Name) + ".obj")

    if (!(Test-Path $objFile) -or (Get-Item $file.FullName).LastWriteTime -gt (Get-Item $objFile).LastWriteTime) {
        $job = Start-Job -ScriptBlock {
            param ($file, $objFile, $compilerPdb, $commonFlags, $configFlags)

            $flags = @($commonFlags + $configFlags + @(
                ('/Fd"{0}"' -f $compilerPdb),
                '/c',
                ('/Fo"{0}"' -f $objFile),
                ('"{0}"' -f $file.FullName)
            )) -join ' '

            cmd.exe /c ("cl.exe " + $flags)
        } -ArgumentList $file, $objFile, $compilerPdb, $commonFlags, $configFlags

        $jobs += $job
    } else {
        Write-Host "Skipping $($file.Name), up-to-date."
    }

    $objFiles += $objFile

    # Limit the number of concurrent jobs to avoid CPU overload
    if ($jobs.Count -ge $maxParallel) {
        $jobs | ForEach-Object { Receive-Job -Job $_ -Wait; Remove-Job -Id $_.Id }
        $jobs = @()
    }
}

# Wait for any remaining compilation jobs to finish
if ($jobs.Count -gt 0) {
    Write-Host "Waiting for compilation jobs to finish..."
    $jobs | ForEach-Object { Receive-Job -Job $_ -Wait }
    Remove-Job -Force -Id ($jobs | ForEach-Object { $_.Id })
}

# Linking step
Write-Host "Linking executable (via response file)..."

$linkRsp = Join-Path $ConfigBuildDir "link.rsp"
$exeOut  = Join-Path $ConfigBuildDir "TestsRunner.exe"
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

# Important: use ASCII/utf8NoBOM, NOT the default UTF-16
Set-Content -Path $linkRsp -Value ($lines -join [Environment]::NewLine) -Encoding ASCII

# Run the linker with the RSP
cmd.exe /c "link.exe /nologo @`"$linkRsp`""

# Stop timing
$endTime = $startTime.Elapsed
Write-Host "$Config build completed in $($endTime.TotalMilliseconds) ms."
Write-Host "Output: $exeOut"
