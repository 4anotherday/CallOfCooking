rem copia las dlls en caso de que sean nuevas -noexistan- o se hayan modificado. Version inicial 2.01.08
rem DEBUGx86
xcopy ..\Motor\dependencies\PhysX\Buildx86\debug\glut32.dll ..\bin\ /s /d /y
xcopy ..\Motor\dependencies\PhysX\Buildx86\debug\PhysX_64.dll ..\bin\ /s /d /y
xcopy ..\Motor\dependencies\PhysX\Buildx86\debug\PhysXCommon_64.dll ..\bin\ /s /d /y
xcopy ..\Motor\dependencies\PhysX\Buildx86\debug\PhysXCooking_64.dll ..\bin\ /s /d /y
xcopy ..\Motor\dependencies\PhysX\Buildx86\debug\PhysXDevice64.dll ..\bin\ /s /d /y
xcopy ..\Motor\dependencies\PhysX\Buildx86\debug\PhysXFoundation_64.dll ..\bin\ /s /d /y
xcopy ..\Motor\dependencies\PhysX\Buildx86\debug\PhysXGpu_64.dll ..\bin\ /s /d /y
exit 0