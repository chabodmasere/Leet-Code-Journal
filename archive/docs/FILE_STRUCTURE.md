# Complete File Structure

## Project Directory Tree

```
Leet_Code_Journal/
│
├── compiler/                      # Compiler source code
│   ├── token.h                    # Token type definitions
│   ├── token.cpp                  # Token implementation
│   ├── lexer.h                    # Lexer interface
│   ├── lexer.cpp                  # Lexer implementation
│   ├── ast.h                      # AST node definitions
│   ├── ast.cpp                    # AST implementation
│   ├── parser.h                   # Parser interface
│   ├── parser.cpp                 # Parser implementation
│   ├── interpreter.h              # Interpreter interface
│   └── interpreter.cpp            # Interpreter implementation
│
├── examples/                      # Example C++ programs
│   ├── hello.cpp                  # Hello World
│   ├── variables.cpp              # Variables and arithmetic
│   ├── conditionals.cpp           # If-else statements
│   ├── loops.cpp                  # While and for loops
│   ├── functions.cpp              # Function definitions
│   └── fibonacci.cpp              # Fibonacci calculator
│
├── main.cpp                       # Compiler driver/entry point
├── Makefile                       # Build file for Make
├── CMakeLists.txt                 # CMake configuration
├── build.bat                      # Windows build script
├── build.sh                       # Linux/macOS build script
│
├── README.md                      # User guide and documentation
├── BUILD_GUIDE.md                 # Detailed build instructions
├── PROJECT_SUMMARY.md             # Project overview
├── ARCHITECTURE.md                # Architecture documentation
├── FILE_STRUCTURE.md              # This file
│
├── .gitignore                     # Git ignore patterns
└── 1.0 Two Sum (easy).cpp         # Original LeetCode file
```

## File Descriptions

### Compiler Core (`compiler/` directory)

#### token.h (90 lines)
**Purpose**: Define token types and Token class

**Contents**:
- `TokenType` enum with all token types
- `Token` class with type, value, line, column
- `keywords` map for keyword recognition
- Helper functions for token string conversion

**Key Types**:
- Literals: INTEGER, FLOAT, STRING, CHAR, TRUE, FALSE
- Keywords: INT, FLOAT_TYPE, IF, ELSE, WHILE, FOR, etc.
- Operators: PLUS, MINUS, MULTIPLY, EQUAL, LESS, etc.
- Delimiters: LPAREN, RPAREN, LBRACE, SEMICOLON, etc.

#### token.cpp (70 lines)
**Purpose**: Implement Token class methods

**Functions**:
- `toString()` - Convert token to string representation
- `typeToString()` - Convert token type to string

#### lexer.h (30 lines)
**Purpose**: Lexer class interface

**Key Methods**:
- `getNextToken()` - Get next token from source
- `tokenize()` - Convert entire source to token list

**Private Methods**:
- `advance()` - Move to next character
- `skipWhitespace()` - Skip whitespace
- `skipComment()` - Skip comments
- `number()` - Parse numbers
- `string()` - Parse strings
- `identifier()` - Parse identifiers

#### lexer.cpp (370 lines)
**Purpose**: Implement lexical analysis

**Features**:
- Character-by-character scanning
- Multi-character operator recognition
- String escape sequences
- Comment handling (// and /* */)
- Number parsing (int and float)
- Keyword vs identifier distinction

#### ast.h (230 lines)
**Purpose**: Define Abstract Syntax Tree nodes

**Node Hierarchy**:
```
ASTNode (base)
├── Expression
│   ├── IntegerLiteral
│   ├── FloatLiteral
│   ├── StringLiteral
│   ├── BoolLiteral
│   ├── Identifier
│   ├── BinaryOp
│   ├── UnaryOp
│   └── FunctionCall
├── Statement
│   ├── VariableDeclaration
│   ├── Assignment
│   ├── IfStatement
│   ├── WhileStatement
│   ├── ForStatement
│   ├── ReturnStatement
│   ├── ExpressionStatement
│   ├── Block
│   ├── CoutStatement
│   └── CinStatement
├── FunctionDeclaration
└── Program
```

**Visitor Pattern**:
- `ASTVisitor` interface
- `accept()` method in each node

#### ast.cpp (100 lines)
**Purpose**: Implement AST node accept methods

**Pattern**: Each node implements `accept(ASTVisitor&)`

#### parser.h (50 lines)
**Purpose**: Parser class interface

**Key Methods**:
- `parse()` - Entry point
- `parseProgram()` - Parse entire program
- `parseFunctionDeclaration()` - Parse functions
- `parseStatement()` - Parse statements
- `parseExpression()` - Parse expressions

**Expression Parsing** (by precedence):
- `parseLogicalOr()`
- `parseLogicalAnd()`
- `parseEquality()`
- `parseComparison()`
- `parseAddition()`
- `parseMultiplication()`
- `parseUnary()`
- `parsePrimary()`

#### parser.cpp (500 lines)
**Purpose**: Implement syntax analysis

**Features**:
- Recursive descent parsing
- Operator precedence handling
- Error reporting with line/column
- Support for all language constructs

**Parsing Strategy**:
- Top-down, one-pass
- Predictive parsing
- Error recovery

#### interpreter.h (70 lines)
**Purpose**: Interpreter class interface

**Key Components**:
- `Value` type (variant<int, float, string, bool>)
- Symbol table (map<string, Value>)
- Function table (map<string, FunctionDeclaration*>)

**Visitor Methods**: One for each AST node type

#### interpreter.cpp (450 lines)
**Purpose**: Implement code execution

**Features**:
- Direct AST interpretation
- Variable management
- Function calls with recursion
- Type coercion
- Runtime error checking

**Key Functions**:
- `evaluate()` - Evaluate expressions
- `execute()` - Execute statements
- `add()`, `subtract()`, etc. - Arithmetic operations
- `isTruthy()` - Boolean conversion
- `valueToString()` - Value to string conversion

### Main Driver

#### main.cpp (100 lines)
**Purpose**: Compiler entry point and CLI

**Features**:
- Command-line argument parsing
- File reading
- Multiple execution modes:
  - `-t` / `--tokens`: Show tokens only
  - `-p` / `--parse`: Parse only
  - `-r` / `--run`: Run program (default)
  - `-h` / `--help`: Show help

**Flow**:
1. Parse arguments
2. Read source file
3. Tokenize
4. Parse
5. Interpret (if requested)
6. Handle errors

### Build System

#### Makefile (25 lines)
**Purpose**: Build automation for Unix-like systems

**Targets**:
- `all` - Build compiler (default)
- `clean` - Remove build artifacts
- `run` - Build and run

**Variables**:
- `CXX` - Compiler (g++)
- `CXXFLAGS` - Compiler flags
- `SOURCES` - Source files
- `OBJECTS` - Object files

#### CMakeLists.txt (25 lines)
**Purpose**: Cross-platform build configuration

**Features**:
- C++17 requirement
- Platform-specific warnings
- Include directories
- Executable target

**Usage**:
```bash
mkdir build && cd build
cmake ..
cmake --build .
```

#### build.bat (15 lines)
**Purpose**: Windows build script

**Actions**:
1. Compile all source files
2. Link into executable
3. Report success/failure

**Requirements**: MinGW or MSVC

#### build.sh (30 lines)
**Purpose**: Linux/macOS build script

**Features**:
- Auto-detect compiler (g++ or clang++)
- Compile with C++17
- Error handling
- Usage instructions

### Examples

#### hello.cpp (7 lines)
**Demonstrates**: Basic output
```cpp
int main() {
    cout << "Hello, World!" << endl;
    return 0;
}
```

#### variables.cpp (13 lines)
**Demonstrates**: Variables and arithmetic
- Variable declaration
- Arithmetic operations
- Output formatting

#### conditionals.cpp (26 lines)
**Demonstrates**: Control flow
- If-else statements
- Nested conditionals
- Comparison operators

#### loops.cpp (31 lines)
**Demonstrates**: Iteration
- While loops
- For loops
- Nested loops
- Loop variables

#### functions.cpp (27 lines)
**Demonstrates**: Functions
- Function declaration
- Function calls
- Recursion
- Return values

#### fibonacci.cpp (19 lines)
**Demonstrates**: Advanced recursion
- Recursive algorithm
- Multiple function calls
- Loop with function calls

### Documentation

#### README.md (300 lines)
**Purpose**: Main user documentation

**Sections**:
- Features overview
- Project structure
- Building instructions
- Usage examples
- Command-line options
- Language features
- Limitations
- Future enhancements

#### BUILD_GUIDE.md (250 lines)
**Purpose**: Detailed build instructions

**Sections**:
- Prerequisites for each platform
- Multiple build methods
- Troubleshooting
- Platform-specific notes
- Quick start guide

#### PROJECT_SUMMARY.md (200 lines)
**Purpose**: Project overview

**Sections**:
- What has been created
- Supported features
- Architecture overview
- File statistics
- Technical highlights
- Educational value

#### ARCHITECTURE.md (400 lines)
**Purpose**: Technical architecture documentation

**Sections**:
- System overview with diagrams
- Component details
- Data flow examples
- Design patterns
- Error handling
- Performance characteristics

#### FILE_STRUCTURE.md (This file)
**Purpose**: Complete file listing and descriptions

### Configuration

#### .gitignore (30 lines)
**Purpose**: Git ignore patterns

**Ignores**:
- Compiled executables
- Object files
- Build directories
- IDE files
- OS files
- Temporary files

### Original Files

#### 1.0 Two Sum (easy).cpp
**Purpose**: Original LeetCode problem (preserved)

**Status**: Not part of compiler, kept for reference

## File Statistics

### Source Code
| Category | Files | Lines |
|----------|-------|-------|
| Compiler Core | 10 | ~1,800 |
| Main Driver | 1 | ~100 |
| Examples | 6 | ~150 |
| **Total Code** | **17** | **~2,050** |

### Documentation
| File | Lines |
|------|-------|
| README.md | ~300 |
| BUILD_GUIDE.md | ~250 |
| PROJECT_SUMMARY.md | ~200 |
| ARCHITECTURE.md | ~400 |
| FILE_STRUCTURE.md | ~400 |
| **Total Docs** | **~1,550** |

### Build System
| File | Lines |
|------|-------|
| Makefile | ~25 |
| CMakeLists.txt | ~25 |
| build.bat | ~15 |
| build.sh | ~30 |
| **Total Build** | **~95** |

### Grand Total
- **Files**: 27
- **Lines of Code**: ~2,050
- **Lines of Documentation**: ~1,550
- **Lines of Build Scripts**: ~95
- **Total Lines**: ~3,695

## Dependencies

### External Dependencies
- **None!** - Pure C++17 standard library

### Standard Library Usage
- `<string>` - String handling
- `<vector>` - Dynamic arrays
- `<map>` - Symbol tables
- `<memory>` - Smart pointers
- `<variant>` - Value types
- `<iostream>` - I/O
- `<fstream>` - File I/O
- `<sstream>` - String streams
- `<cctype>` - Character classification
- `<stdexcept>` - Exceptions

## Build Outputs

### Executables
- `cpp_compiler` (Linux/macOS)
- `cpp_compiler.exe` (Windows)

### Intermediate Files
- `*.o` - Object files
- `compiler/*.o` - Compiler object files

### Build Directories
- `build/` - CMake build directory
- `.cmake/` - CMake cache

## Usage Flow

```
1. User writes C++ program → example.cpp
2. User runs compiler → ./cpp_compiler example.cpp
3. main.cpp reads file
4. lexer.cpp tokenizes
5. parser.cpp builds AST
6. interpreter.cpp executes
7. Output displayed
```

## Modification Guide

### To add a new operator:
1. Add token type in `token.h`
2. Add lexer recognition in `lexer.cpp`
3. Add parsing in `parser.cpp`
4. Add evaluation in `interpreter.cpp`

### To add a new statement:
1. Add AST node in `ast.h`
2. Implement accept in `ast.cpp`
3. Add visitor method in `interpreter.h`
4. Add parsing in `parser.cpp`
5. Add execution in `interpreter.cpp`

### To add a new example:
1. Create `examples/newexample.cpp`
2. Test with `./cpp_compiler examples/newexample.cpp`
3. Update README.md with example

## Conclusion

This file structure represents a **complete, well-organized compiler project** with:

✅ Clear separation of concerns
✅ Comprehensive documentation
✅ Multiple build options
✅ Working examples
✅ Educational value
✅ Professional organization

Total: **27 files, ~3,695 lines** of code and documentation!
