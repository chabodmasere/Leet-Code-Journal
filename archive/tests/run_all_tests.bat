@echo off
echo =========================================
echo   C++ Compiler - Complete Test Suite
echo =========================================
echo.

set PASSED=0
set FAILED=0

REM Check if compiler exists
if not exist "cpp_compiler.exe" (
    echo Error: cpp_compiler.exe not found!
    echo Please build the compiler first using: build.bat
    exit /b 1
)

echo === Example Programs ===
echo.

echo Test 1: Hello World
cpp_compiler.exe examples\hello.cpp
if %errorlevel% equ 0 (
    set /a PASSED+=1
    echo PASS
) else (
    set /a FAILED+=1
    echo FAIL
)
echo.

echo Test 2: Variables
cpp_compiler.exe examples\variables.cpp
if %errorlevel% equ 0 (
    set /a PASSED+=1
    echo PASS
) else (
    set /a FAILED+=1
    echo FAIL
)
echo.

echo Test 3: Conditionals
cpp_compiler.exe examples\conditionals.cpp
if %errorlevel% equ 0 (
    set /a PASSED+=1
    echo PASS
) else (
    set /a FAILED+=1
    echo FAIL
)
echo.

echo Test 4: Loops
cpp_compiler.exe examples\loops.cpp
if %errorlevel% equ 0 (
    set /a PASSED+=1
    echo PASS
) else (
    set /a FAILED+=1
    echo FAIL
)
echo.

echo Test 5: Functions
cpp_compiler.exe examples\functions.cpp
if %errorlevel% equ 0 (
    set /a PASSED+=1
    echo PASS
) else (
    set /a FAILED+=1
    echo FAIL
)
echo.

echo Test 6: Fibonacci
cpp_compiler.exe examples\fibonacci.cpp
if %errorlevel% equ 0 (
    set /a PASSED+=1
    echo PASS
) else (
    set /a FAILED+=1
    echo FAIL
)
echo.

echo =========================================
echo   Test Results
echo =========================================
echo Passed: %PASSED%
echo Failed: %FAILED%
set /a TOTAL=%PASSED%+%FAILED%
echo Total:  %TOTAL%
echo.

if %FAILED% equ 0 (
    echo All tests passed!
    exit /b 0
) else (
    echo Some tests failed!
    exit /b 1
)
