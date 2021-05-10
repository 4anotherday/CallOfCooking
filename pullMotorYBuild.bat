cd Motor/
git checkout main
git pull

call "%ProgramFiles(x86)%\Microsoft Visual Studio\2019\Community\Common7\Tools\VsMSBuildCmd.bat"

msbuild Motor.sln /p:Configuration=Release /p:Platform=x64 /t:MotorUnitario

exit 0;