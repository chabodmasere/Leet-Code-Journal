@echo off
echo Building C++ Compiler...

g++ -std=c++17 -Wall -Wextra -I. -o cpp_compiler.exe main.cpp compiler/token.cpp compiler/lexer.cpp compiler/ast.cpp compiler/parser.cpp compiler/interpreter.cpp

if %errorlevel% equ 0 (
    echo Build successful! Executable: cpp_compiler.exe
    echo.
    echo Usage: cpp_compiler.exe [options] ^<source_file^>
    echo Example: cpp_compiler.exe examples/hello.cpp
) else (
    echo Build failed!
)

pause
