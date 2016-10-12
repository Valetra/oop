set PROGRAM="%~1"

%PROGRAM% "Debug/file1.txt" "Debug/file2.txt"
if %ERRORLEVEL% EQU 1 goto err

%PROGRAM% "" ""
if %ERRORLEVEL% EQU 0 goto err

%PROGRAM% "Debug/file1.txt" "Debug/file2.txt" "Debug/file3.txt"
if %ERRORLEVEL% EQU 0 goto err

%PROGRAM% "Debug/file3.txt" "Debug/file2.txt"
if %ERRORLEVEL% EQU 0 goto err

%PROGRAM% "Debug/file4.txt" "Debug/file5.txt"
if %ERRORLEVEL% EQU 0 goto err

echo Program testing succeded
exit 0

:err
echo Program testing failed
exit 1