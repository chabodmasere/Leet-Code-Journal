cmake_minimum_required(VERSION 3.10)
project(CPPCompiler)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add compiler warnings
if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Source files
set(SOURCES
    main.cpp
    compiler/token.cpp
    compiler/lexer.cpp
    compiler/ast.cpp
    compiler/parser.cpp
    compiler/interpreter.cpp
)

# Create executable
add_executable(cpp_compiler ${SOURCES})

# Include directories
target_include_directories(cpp_compiler PRIVATE ${CMAKE_SOURCE_DIR})
