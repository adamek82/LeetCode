# PowerShell script for incremental compilation

$vcvars64 = "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"
$cppFiles = Get-ChildItem -Path $PSScriptRoot -Filter "*.cpp"
$objFiles = @()

# Load Visual Studio environment once at the start
Write-Host "Setting up Visual Studio environment..."
cmd.exe /c "call `"$vcvars64`" && set" | ForEach-Object {
    if ($_ -match "^(.*?)=(.*)$") {
        [System.Environment]::SetEnvironmentVariable($matches[1], $matches[2], [System.EnvironmentVariableTarget]::Process)
    }
}

# Compile only changed files
foreach ($file in $cppFiles) {
    $objFile = "$PSScriptRoot\.vscode\" + [System.IO.Path]::GetFileNameWithoutExtension($file.Name) + ".obj"

    if (!(Test-Path $objFile) -or (Get-Item $file.FullName).LastWriteTime -gt (Get-Item $objFile).LastWriteTime) {
        Write-Host "Compiling $($file.Name)..."
        cmd.exe /c "cl.exe /std:c++20 /Zi /EHsc /nologo /c /Fo`"$objFile`" `"$($file.FullName)`""
    } else {
        Write-Host "Skipping $($file.Name), up-to-date."
    }

    $objFiles += "`"$objFile`""
}

# Linking step
Write-Host "Linking executable..."
$linkCmd = "cl.exe /nologo /Fe`"$PSScriptRoot\.vscode\testsRunner.exe`" " + ($objFiles -join " ")
cmd.exe /c $linkCmd

Write-Host "Build completed."
