#!/bin/bash

echo "Building C++ Compiler..."

# Detect compiler
if command -v g++ &> /dev/null; then
    COMPILER="g++"
elif command -v clang++ &> /dev/null; then
    COMPILER="clang++"
else
    echo "Error: No C++ compiler found. Please install g++ or clang++."
    exit 1
fi

echo "Using compiler: $COMPILER"

# Compile
$COMPILER -std=c++17 -Wall -Wextra -I. -o cpp_compiler \
    main.cpp \
    compiler/token.cpp \
    compiler/lexer.cpp \
    compiler/ast.cpp \
    compiler/parser.cpp \
    compiler/interpreter.cpp

if [ $? -eq 0 ]; then
    echo "Build successful! Executable: cpp_compiler"
    echo ""
    echo "Usage: ./cpp_compiler [options] <source_file>"
    echo "Example: ./cpp_compiler examples/hello.cpp"
    echo ""
    echo "Run './cpp_compiler -h' for more options"
else
    echo "Build failed!"
    exit 1
fi
