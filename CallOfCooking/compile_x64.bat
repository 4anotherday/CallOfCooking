rem copia las dlls en caso de que sean nuevas -noexistan- o se hayan modificado. Version inicial 2.01.08

rem SDL
xcopy ..\Motor\dependencies\SDL2\Build\Debug\SDL2d.dll ..\bin\ /s /d /y
xcopy ..\Motor\dependencies\SDL2\Build\Release\SDL2.dll ..\bin\ /s /d /y

rem FMOD
xcopy ..\Motor\dependencies\Fmod\Buildx64\fmod.dll ..\bin\ /s /d /y
xcopy ..\Motor\dependencies\Fmod\Buildx64\fmodL.dll ..\bin\ /s /d /y

rem OGRE
rem copia las dlls implicitas a bin
xcopy ..\Motor\dependencies\Ogre\Build\bin\debug\OgreMain_d.dll ..\bin\ /s /d /y
xcopy ..\Motor\dependencies\Ogre\Build\bin\release\OgreMain.dll ..\bin\ /s /d /y
xcopy ..\Motor\dependencies\Ogre\Build\bin\release\zlib.dll ..\bin\ /s /d /y
xcopy ..\Motor\dependencies\Ogre\Build\bin\debug\OgreRTShaderSystem_d.dll ..\bin\ /s /d /y
xcopy ..\Motor\dependencies\Ogre\Build\bin\release\OgreRTShaderSystem.dll ..\bin\ /s /d /y
xcopy ..\Motor\dependencies\Ogre\Build\bin\release\OgreOverlay.dll ..\bin\ /s /d /y
xcopy ..\Motor\dependencies\Ogre\Build\bin\debug\OgreOverlay_d.dll ..\bin\ /s /d /y

rem copia las dlls explicitas de los plugins a bin\Ogre[Debug/Release]
xcopy ..\Motor\dependencies\Ogre\Build\bin\debug\Codec_STBI_d.dll ..\bin\OgreDEBUG\ /s /d /y
xcopy ..\Motor\dependencies\Ogre\Build\bin\debug\RenderSystem_Direct3d11_d.dll ..\bin\OgreDEBUG\ /s /d /y
xcopy ..\Motor\dependencies\Ogre\Build\bin\release\Codec_STBI.dll ..\bin\OgreRELEASE\ /s /d /y
xcopy ..\Motor\dependencies\Ogre\Build\bin\release\RenderSystem_Direct3d11.dll ..\bin\OgreRELEASE\ /s /d /y

rem LUA
xcopy ..\Motor\dependencies\Lua\Buildx64\lua54.dll ..\bin\ /s /d /y