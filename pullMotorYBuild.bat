cd Motor/
git checkout main
git pull
call Compile.bat
cd ../
msbuild CallOfCooking.sln /p:Configuration=Release /p:Platform=x64