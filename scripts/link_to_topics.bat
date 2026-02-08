@echo off
REM Script to link a problem to topic directories
REM Usage: link_to_topics.bat <problem_path> <topic1> [topic2] [topic3] ...
REM Example: link_to_topics.bat problems\easy\001_two_sum arrays hash-table

setlocal enabledelayedexpansion

if "%~1"=="" (
    echo Error: Problem path is required
    echo Usage: link_to_topics.bat ^<problem_path^> ^<topic1^> [topic2] [topic3] ...
    echo Example: link_to_topics.bat problems\easy\001_two_sum arrays hash-table
    exit /b 1
)

if "%~2"=="" (
    echo Error: At least one topic is required
    echo Usage: link_to_topics.bat ^<problem_path^> ^<topic1^> [topic2] [topic3] ...
    echo Example: link_to_topics.bat problems\easy\001_two_sum arrays hash-table
    exit /b 1
)

set "PROBLEM_PATH=%~1"
set "PROBLEM_NAME="

REM Extract problem name from path
for %%F in ("%PROBLEM_PATH%") do set "PROBLEM_NAME=%%~nxF"

if not exist "%PROBLEM_PATH%" (
    echo Error: Problem path does not exist: %PROBLEM_PATH%
    exit /b 1
)

echo.
echo Linking problem: %PROBLEM_NAME%
echo From: %PROBLEM_PATH%
echo.

REM Process each topic argument
shift
:loop
if "%~1"=="" goto :done

set "TOPIC=%~1"
set "TOPIC_DIR=topics\%TOPIC%"

REM Create topic directory if it doesn't exist
if not exist "%TOPIC_DIR%" (
    echo Creating topic directory: %TOPIC_DIR%
    mkdir "%TOPIC_DIR%"
)

REM Create junction point
set "LINK_PATH=%TOPIC_DIR%\%PROBLEM_NAME%"

if exist "%LINK_PATH%" (
    echo   [SKIP] Link already exists: %LINK_PATH%
) else (
    cmd /c mklink /J "%LINK_PATH%" "%PROBLEM_PATH%" >nul 2>&1
    if !errorlevel! equ 0 (
        echo   [OK] Linked to: %TOPIC%\%PROBLEM_NAME%
    ) else (
        echo   [ERROR] Failed to create link in: %TOPIC%
    )
)

shift
goto :loop

:done
echo.
echo Done! Problem linked to topics.
echo.
echo You can now access this problem from:
echo   - Original: %PROBLEM_PATH%
shift
:show_topics
if "%~1"=="" goto :end
echo   - Topic: topics\%~1\%PROBLEM_NAME%
shift
goto :show_topics

:end
echo.
