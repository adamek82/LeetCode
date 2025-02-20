# PowerShell script for incremental compilation

$vcvars64 = "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"
$vscodeDir = "$PSScriptRoot\.vscode"
$cppFiles  = Get-ChildItem -Path $PSScriptRoot -Filter "*.cpp"

# Ensure the .vscode directory exists for storing .obj files
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

# Compile only changed .cpp files
foreach ($file in $cppFiles) {
    $objFile = Join-Path $vscodeDir ([System.IO.Path]::GetFileNameWithoutExtension($file.Name) + ".obj")

    if (!(Test-Path $objFile) -or (Get-Item $file.FullName).LastWriteTime -gt (Get-Item $objFile).LastWriteTime) {
        Write-Host "Compiling $($file.Name)..."
        # NOTE: Removed /Fd. Added /Od for no optimization.
        cmd.exe /c "cl.exe /std:c++20 /Zi /Od /EHsc /nologo /c /Fo`"$objFile`" `"$($file.FullName)`""
    } else {
        Write-Host "Skipping $($file.Name), up-to-date."
    }

    $objFiles += "`"$objFile`""
}

Write-Host "Linking executable..."
# NOTE: Removed /Fd here, too. /DEBUG will produce a .pdb that references the .exe correctly.
$linkCmd = "cl.exe /nologo " + ($objFiles -join " ") +
           " /link /DEBUG /OUT:`"$vscodeDir\TestsRunner.exe`" /LTCG:OFF"
cmd.exe /c $linkCmd

Write-Host "Build completed."
