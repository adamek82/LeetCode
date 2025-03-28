# PowerShell script for parallel incremental compilation with timing (for C)

$vcvars64 = "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"
$vscodeDir = "$PSScriptRoot\.vscode"
$cFiles  = Get-ChildItem -Path $PSScriptRoot -Filter "*.c"

# Ensure the .vscode directory exists for storing .obj files
if (!(Test-Path $vscodeDir)) {
    New-Item -ItemType Directory -Path $vscodeDir | Out-Null
}

$maxParallel = [System.Environment]::ProcessorCount
$jobs = @()
$objFiles = @()

# Start timing
$startTime = [System.Diagnostics.Stopwatch]::StartNew()

# Load VS environment once
Write-Host "Setting up Visual Studio environment..."
cmd.exe /c "call `"$vcvars64`" && set" | ForEach-Object {
    if ($_ -match "^(.*?)=(.*)$") {
        [System.Environment]::SetEnvironmentVariable($matches[1], $matches[2], [System.EnvironmentVariableTarget]::Process)
    }
}

foreach ($file in $cFiles) {
    $objFile = Join-Path $vscodeDir ([System.IO.Path]::GetFileNameWithoutExtension($file.Name) + ".obj")

    # Only recompile if changed
    if (!(Test-Path $objFile) -or (Get-Item $file.FullName).LastWriteTime -gt (Get-Item $objFile).LastWriteTime) {
        Write-Host "Compiling $($file.Name)..."

        $job = Start-Job -ScriptBlock {
            param ($file, $objFile)
            # For C code, remove /EHsc and choose a C standard switch, e.g. /std:c17
            cmd.exe /c "cl.exe /std:c17 /Zi /Od /nologo /FS /c /Fo`"$objFile`" `"$($file.FullName)`""
        } -ArgumentList $file, $objFile

        $jobs += $job
    }
    else {
        Write-Host "Skipping $($file.Name), up-to-date."
    }

    $objFiles += "`"$objFile`""

    # Limit concurrency
    if ($jobs.Count -ge $maxParallel) {
        $jobs | ForEach-Object { Receive-Job -Job $_ -Wait; Remove-Job -Id $_.Id }
        $jobs = @()
    }
}

# Wait for any remaining compile jobs
if ($jobs.Count -gt 0) {
    Write-Host "Waiting for compilation jobs to finish..."
    $jobs | ForEach-Object { Receive-Job -Job $_ -Wait }
    Remove-Job -Force -Id ($jobs | ForEach-Object { $_.Id })
}

# Linking step
Write-Host "Linking executable..."
$linkCmd = "cl.exe /nologo " + ($objFiles -join " ") + " /link /DEBUG /OUT:`"$vscodeDir\TestsRunnerC.exe`" /LTCG:OFF"
cmd.exe /c $linkCmd

# Stop timing
$endTime = $startTime.Elapsed
Write-Host "Build completed in $($endTime.TotalMilliseconds) ms."
