set PROGRAM="%~1"

%PROGRAM% "-1"
if %ERRORLEVEL% EQU 0 goto err

%PROGRAM% "64" 
if %ERRORLEVEL% EQU 1 goto err

%PROGRAM% "255" 
if %ERRORLEVEL% EQU 1 goto err

%PROGRAM% "256" 
if %ERRORLEVEL% EQU 0 goto err

echo Program testing succeded
exit 0

:err
echo Program testing failed
exit 1