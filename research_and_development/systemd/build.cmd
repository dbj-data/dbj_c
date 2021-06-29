@cls

@if [%1] == [clean] goto clean

:build
clang-cl /TC /Zi main.c /o out/test.exe
@goto exit

:clean
@del out\*.pdb
@del out\*.ilk
@del out\*.exe
@goto exit

:exit