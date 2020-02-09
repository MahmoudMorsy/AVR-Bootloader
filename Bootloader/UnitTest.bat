md "T"
del "UniTest.exe"
FOR /R "Bootloader" %%i IN (*.c *.h) DO COPY "%%i" "T"
cd "T"
setlocal enabledelayedexpansion enableextensions
set LIST=
for %%x in (*.c) do set LIST=!LIST! %%x
set LIST=%LIST:~1%
gcc -o ../UnitTest %LIST%
cd ..
UnitTest.exe
rmdir /Q /S "T"
set /p DUMMY=Hit ENTER to exist this window...