@echo off
@rem
@rem it is much easier to tame C/C++ compiler from a simple batch file
@rem than fighting with quirks of VS Code "auto build"
@rem
@cls
@setlocal
set "sourcebasename=examples"

set "sourcefilename=%sourcebasename%"
set "build=.\build"
@md %build% 2>nul

if [%1]==[clean] goto clean

@set "INCLUDE=F:\machine_wide;%INCLUDE%"

@rem /Zi -- debug builds + pdb file
@rem /TC -- threat all as C
clang-cl lib/fort.c %sourcefilename%.c /nologo /I "f:\\machine_wide" /MDd /D_DEBUG /Zi /TC /W3 /Fo%build%\ /Fe%build%\%sourcebasename%.exe 

@echo.
@echo Done building: %build%\%sourcebasename%.exe
@echo.
@goto eof

:clean
del .\build\%sourcebasename%.*
@goto eof

:eof
@endlocal