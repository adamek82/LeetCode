# PowerShell script for parallel incremental compilation

$vcvars64 = "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"
$vscodeDir = "$PSScriptRoot\.vscode"
$cppFiles  = Get-ChildItem -Path $PSScriptRoot -Filter "*.cpp"

# Ensure the .vscode directory exists for storing .obj files
if (!(Test-Path $vscodeDir)) {
    New-Item -ItemType Directory -Path $vscodeDir | Out-Null
}

# Detect the number of logical processors
$maxParallel = [System.Environment]::ProcessorCount
$jobs = @()
$objFiles = @()

# Load Visual Studio environment once at the start
Write-Host "Setting up Visual Studio environment..."
cmd.exe /c "call `"$vcvars64`" && set" | ForEach-Object {
    if ($_ -match "^(.*?)=(.*)$") {
        [System.Environment]::SetEnvironmentVariable($matches[1], $matches[2], [System.EnvironmentVariableTarget]::Process)
    }
}

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
Write-Host "Linking executable..."
$linkCmd = "cl.exe /nologo " + ($objFiles -join " ") + " /link /DEBUG /OUT:`"$vscodeDir\TestsRunner.exe`" /LTCG:OFF"
cmd.exe /c $linkCmd

Write-Host "Build completed."
