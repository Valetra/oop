set PROGRAM="%~1"

%PROGRAM% "matrix.txt"
if %ERRORLEVEL% EQU 1 goto err

%PROGRAM% "matrix2.txt"
if %ERRORLEVEL% EQU 1 goto err

echo Program testing succeded
exit 0

:err
echo Program testing failed
exit 1