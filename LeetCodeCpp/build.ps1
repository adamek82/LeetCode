# PowerShell script for parallel incremental compilation with timing

$vcvars64 = "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"
$vscodeDir = "$PSScriptRoot\.vscode"
$cppFiles  = Get-ChildItem -Path $PSScriptRoot -Filter "*.cpp"

# Ensure the .vscode directory exists for storing .obj files
if (!(Test-Path $vscodeDir)) {
    New-Item -ItemType Directory -Path $vscodeDir | Out-Null
}

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

# Compile only changed .cpp files in parallel
foreach ($file in $cppFiles) {
    $objFile = Join-Path $vscodeDir ([System.IO.Path]::GetFileNameWithoutExtension($file.Name) + ".obj")

    if (!(Test-Path $objFile) -or (Get-Item $file.FullName).LastWriteTime -gt (Get-Item $objFile).LastWriteTime) {
        Write-Host "Compiling $($file.Name)..."

        # Start parallel compilation
        $job = Start-Job -ScriptBlock {
            param ($file, $objFile)
            cmd.exe /c "cl.exe /std:c++20 /Zi /Od /EHsc /nologo /FS /c /Fo`"$objFile`" `"$($file.FullName)`""
        } -ArgumentList $file, $objFile

        $jobs += $job
    } else {
        Write-Host "Skipping $($file.Name), up-to-date."
    }

    $objFiles += "`"$objFile`""

    # Limit the number of concurrent jobs to avoid CPU overload
    if ($jobs.Count -ge $maxParallel) {
        $jobs | ForEach-Object { Receive-Job -Job $_ -Wait; Remove-Job -Id $_.Id }
        $jobs = @()  # Reset the job queue
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

$linkRsp = Join-Path $vscodeDir "link.rsp"
$exeOut  = Join-Path $vscodeDir "TestsRunner.exe"

# Build RSP contents: each .obj on a separate line + linker options
$lines = @()
$lines += ($objFiles | ForEach-Object { '"{0}"' -f $_ })
$lines += '/DEBUG'
$lines += ('/OUT:"{0}"' -f $exeOut)
$lines += '/LTCG:OFF'

# Important: use ASCII/utf8NoBOM, NOT the default UTF-16
Set-Content -Path $linkRsp -Value ($lines -join [Environment]::NewLine) -Encoding ASCII

# Run the linker with the RSP (if vcvars64 is needed: call vcvars before link)
cmd.exe /c "link.exe /nologo @`"$linkRsp`""

# Stop timing
$endTime = $startTime.Elapsed
Write-Host "Build completed in $($endTime.TotalMilliseconds) ms."
