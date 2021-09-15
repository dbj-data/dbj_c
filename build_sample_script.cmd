
@echo off
@rem
@rem this is what we use (modified), if you need it use it
@rem we much preffer bat files to .vscode/tasks.json
@rem
@cls
@setlocal
set "build=.\bin"
@md %build% 2>nul

@if [%1] == [clean] goto clean

set "sourcebasename=you source file basename here"

@rem this is where dbj machine wide is check out on this machine
@rem change it to your liking

@set "INCLUDE=F:\machine_wide;%INCLUDE%"

@rem you need to run VStudio vsvars64.bat beforehand so that clang-cl.exe is found on the path
@rem /Zi -- debug builds + pdb file
@rem /TC -- threat all source as C
@rem /MTd -- use static debug runtime
@rem /MDd -- use debug dll runtime
@clang-cl %sourcebasename%.c /I "F:\machine_wide" /GR- /MTd /D_DEBUG /D_HAS_EXCEPTIONS=0 /nologo /Zi /W3 /Fo%build%\ /Fe%build%\%sourcebasename%.exe 

@echo.
@echo Done building: %build%\%sourcebasename%.exe
@echo.

@goto exit

:clean
@del %build%\*.pdb
@del %build%\*.ilk
@del %build%\*.exe
@del %build%\*.obj
@goto exit

:exit
@endlocal