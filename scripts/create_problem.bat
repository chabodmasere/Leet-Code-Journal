@echo off
REM Script to create a new LeetCode problem file
REM Usage: create_problem.bat <number> <name> <difficulty>
REM Example: create_problem.bat 2 add-two-numbers medium

if "%~3"=="" (
    echo Usage: create_problem.bat ^<number^> ^<name^> ^<difficulty^>
    echo Example: create_problem.bat 2 add-two-numbers medium
    echo.
    echo Difficulty must be: easy, medium, or hard
    exit /b 1
)

set PROBLEM_NUM=%~1
set PROBLEM_NAME=%~2
set DIFFICULTY=%~3

REM Pad number with zeros (e.g., 1 -> 001)
set "PADDED_NUM=00%PROBLEM_NUM%"
set "PADDED_NUM=%PADDED_NUM:~-3%"

REM Create file name
set "FILE_NAME=%PADDED_NUM%_%PROBLEM_NAME%.cpp"
set "FULL_PATH=problems\%DIFFICULTY%\%FILE_NAME%"

REM Check if difficulty is valid
if not "%DIFFICULTY%"=="easy" if not "%DIFFICULTY%"=="medium" if not "%DIFFICULTY%"=="hard" (
    echo Error: Difficulty must be easy, medium, or hard
    exit /b 1
)

REM Check if file already exists
if exist "%FULL_PATH%" (
    echo Error: Problem file already exists: %FULL_PATH%
    exit /b 1
)

REM Create the C++ file
echo Creating problem file: %FULL_PATH%
(
echo /*
echo  * LeetCode Problem %PROBLEM_NUM%: [Problem Name]
echo  * Difficulty: %DIFFICULTY%
echo  * Topics: [Add topics here]
echo  * Link: https://leetcode.com/problems/%PROBLEM_NAME%/
echo  * 
echo  * Problem Description:
echo  * [Add problem description here]
echo  * 
echo  * Example 1:
echo  * Input: 
echo  * Output: 
echo  * Explanation: 
echo  */
echo.
echo #include ^<vector^>
echo #include ^<iostream^>
echo using namespace std;
echo.
echo class Solution {
echo public:
echo     // TODO: Implement solution
echo };
echo.
echo // Test cases
echo int main(^) {
echo     Solution solution;
echo     
echo     // TODO: Add test cases
echo     
echo     return 0;
echo }
) > "%FULL_PATH%"

echo.
echo ✓ Problem file created successfully!
echo.
echo File: %FULL_PATH%
echo.
echo Next steps:
echo   1. Edit the file and add problem description
echo   2. Implement your solution
echo   3. Add test cases
echo   4. Link to topics: scripts\link_to_topics.bat %FULL_PATH% ^<topic1^> [topic2] ...
echo      Example: scripts\link_to_topics.bat %FULL_PATH% arrays hash-table
echo   5. Compile and run: g++ -std=c++17 %FULL_PATH% -o test ^&^& test
