@ECHO OFF
echo --- Running Unit Test Environment, Please wait ---
echo .
md "T"
del "UnitTest.exe" > NUL
FOR /R "Bootloader" %%i IN (*.c *.h) DO COPY "%%i" "T" > NUL
cd "T"
setlocal enabledelayedexpansion enableextensions
set LIST=
for %%x in (*.c) do set LIST=!LIST! %%x
set LIST=%LIST:~1%
gcc -o ../UnitTest %LIST%
cd ..
rmdir /Q /S "T"
echo --------------- TEST CASES RESULTS ---------------
UnitTest.exe
echo ---------------- END OF UNIT TEST ----------------
echo .
set /p DUMMY=Hit ENTER to exist this window...