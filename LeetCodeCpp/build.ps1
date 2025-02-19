# PowerShell script for incremental compilation

$vcvars64 = "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"
$vscodeDir = "$PSScriptRoot\.vscode"
$cppFiles = Get-ChildItem -Path $PSScriptRoot -Filter "*.cpp"
$pdbFile = "$vscodeDir\vc140.pdb"

# Ensure the .vscode directory exists for storing .obj and .pdb files
if (!(Test-Path $vscodeDir)) {
    New-Item -ItemType Directory -Path $vscodeDir | Out-Null
}

$objFiles = @()

# Load Visual Studio environment once at the start
Write-Host "Setting up Visual Studio environment..."
cmd.exe /c "call `"$vcvars64`" && set" | ForEach-Object {
    if ($_ -match "^(.*?)=(.*)$") {
        [System.Environment]::SetEnvironmentVariable($matches[1], $matches[2], [System.EnvironmentVariableTarget]::Process)
    }
}

# Compile only changed files, storing .obj and .pdb files in .vscode/
foreach ($file in $cppFiles) {
    $objFile = "$vscodeDir\" + [System.IO.Path]::GetFileNameWithoutExtension($file.Name) + ".obj"

    if (!(Test-Path $objFile) -or (Get-Item $file.FullName).LastWriteTime -gt (Get-Item $objFile).LastWriteTime) {
        Write-Host "Compiling $($file.Name)..."
        cmd.exe /c "cl.exe /std:c++20 /Zi /EHsc /nologo /c /Fo`"$objFile`" /Fd`"$pdbFile`" `"$($file.FullName)`""
    } else {
        Write-Host "Skipping $($file.Name), up-to-date."
    }

    $objFiles += "`"$objFile`""
}

# Linking step, reading .obj files from .vscode/, and keeping .pdb in .vscode/
Write-Host "Linking executable..."
$linkCmd = "cl.exe /nologo /Fe`"$vscodeDir\testsRunner.exe`" /Fd`"$pdbFile`" " + ($objFiles -join " ")
cmd.exe /c $linkCmd

Write-Host "Build completed."
