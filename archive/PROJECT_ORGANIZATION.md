# Project Organization

This document describes the complete organization of the C++ Compiler project.

## Directory Structure

```
cpp_compiler/
│
├── compiler/                    # Core compiler implementation
│   ├── token.h                 # Token type definitions
│   ├── token.cpp               # Token implementation
│   ├── lexer.h                 # Lexer interface
│   ├── lexer.cpp               # Lexical analyzer implementation
│   ├── ast.h                   # AST node definitions
│   ├── ast.cpp                 # AST implementation
│   ├── parser.h                # Parser interface
│   ├── parser.cpp              # Parser implementation
│   ├── interpreter.h           # Interpreter interface
│   └── interpreter.cpp         # Interpreter implementation
│
├── examples/                    # Example C++ programs
│   ├── hello.cpp               # Hello World
│   ├── variables.cpp           # Variables and arithmetic
│   ├── conditionals.cpp        # If-else statements
│   ├── loops.cpp               # While and for loops
│   ├── functions.cpp           # Functions and recursion
│   └── fibonacci.cpp           # Fibonacci sequence
│
├── docs/                        # Documentation
│   ├── BUILD_GUIDE.md          # Build instructions
│   ├── QUICKSTART.md           # Quick start guide
│   ├── ARCHITECTURE.md         # Technical architecture
│   ├── PROJECT_SUMMARY.md      # Project overview
│   ├── FILE_STRUCTURE.md       # File descriptions
│   └── TESTING_GUIDE.md        # Testing procedures
│
├── scripts/                     # Build and utility scripts
│   ├── build.bat               # Windows build script
│   └── build.sh                # Linux/macOS build script
│
├── tests/                       # Test scripts and test files
│   ├── run_all_tests.bat       # Windows test runner
│   └── run_all_tests.sh        # Linux/macOS test runner
│
├── main.cpp                     # Compiler entry point
├── Makefile                     # Make build configuration
├── CMakeLists.txt              # CMake build configuration
├── .gitignore                  # Git ignore patterns
├── README.md                   # Main documentation
└── PROJECT_ORGANIZATION.md     # This file
```

## File Categories

### 1. Core Compiler Files (compiler/)

**Purpose:** Contains all the compiler implementation code

| File | Lines | Purpose |
|------|-------|---------|
| token.h | 90 | Token type enumeration and Token class definition |
| token.cpp | 70 | Token class implementation |
| lexer.h | 30 | Lexer class interface |
| lexer.cpp | 370 | Tokenization logic |
| ast.h | 230 | AST node class definitions |
| ast.cpp | 100 | AST node implementations |
| parser.h | 50 | Parser class interface |
| parser.cpp | 500 | Parsing logic and AST construction |
| interpreter.h | 70 | Interpreter class interface |
| interpreter.cpp | 450 | Code execution engine |

**Total:** 1,960 lines

### 2. Example Programs (examples/)

**Purpose:** Demonstrate compiler capabilities

| File | Purpose | Features Demonstrated |
|------|---------|----------------------|
| hello.cpp | Hello World | Basic I/O, main function |
| variables.cpp | Variables | Variable declaration, arithmetic |
| conditionals.cpp | Control flow | If-else statements, comparisons |
| loops.cpp | Iteration | While loops, for loops, nested loops |
| functions.cpp | Functions | Function calls, recursion |
| fibonacci.cpp | Advanced | Loops with functions, recursion |

**Total:** ~150 lines

### 3. Documentation (docs/)

**Purpose:** Comprehensive project documentation

| File | Lines | Purpose |
|------|-------|---------|
| BUILD_GUIDE.md | 250 | Detailed build instructions for all platforms |
| QUICKSTART.md | 200 | 5-minute quick start guide |
| ARCHITECTURE.md | 400 | Technical architecture and design |
| PROJECT_SUMMARY.md | 200 | Project overview and statistics |
| FILE_STRUCTURE.md | 400 | Complete file descriptions |
| TESTING_GUIDE.md | 500 | Testing procedures and expected outputs |

**Total:** ~2,000 lines

### 4. Build Scripts (scripts/)

**Purpose:** Automated build processes

| File | Platform | Purpose |
|------|----------|---------|
| build.bat | Windows | Batch script for Windows compilation |
| build.sh | Linux/macOS | Shell script for Unix compilation |

**Total:** ~95 lines

### 5. Test Scripts (tests/)

**Purpose:** Automated testing

| File | Platform | Purpose |
|------|----------|---------|
| run_all_tests.bat | Windows | Run all example programs on Windows |
| run_all_tests.sh | Linux/macOS | Run all example programs on Unix |

**Total:** ~100 lines

### 6. Build Configuration Files

**Purpose:** Build system configuration

| File | Purpose |
|------|---------|
| Makefile | Make build configuration for Unix systems |
| CMakeLists.txt | CMake configuration for cross-platform builds |

**Total:** ~50 lines

### 7. Root Level Files

**Purpose:** Project metadata and entry point

| File | Purpose |
|------|---------|
| main.cpp | Compiler driver and CLI |
| README.md | Main project documentation |
| .gitignore | Git ignore patterns |
| PROJECT_ORGANIZATION.md | This file |

**Total:** ~150 lines

## File Organization Principles

### 1. Separation of Concerns

- **compiler/** - Pure compiler logic, no I/O
- **examples/** - Sample programs to compile
- **docs/** - All documentation in one place
- **scripts/** - Build automation
- **tests/** - Testing automation

### 2. Modularity

Each compiler component is in its own file pair (.h/.cpp):
- Token system
- Lexer
- AST
- Parser
- Interpreter

### 3. Documentation

- Root README.md for quick overview
- docs/ for detailed documentation
- Each major component documented separately

### 4. Build Systems

Multiple build options provided:
- Makefile for Unix
- CMake for cross-platform
- Build scripts for simplicity

### 5. Testing

- Automated test runners
- Example programs serve as test cases
- Testing guide with expected outputs

## Workflow

### Development Workflow

```
1. Edit source files in compiler/
2. Build using scripts/build.sh or scripts/build.bat
3. Test using tests/run_all_tests.sh or tests/run_all_tests.bat
4. Run individual examples for debugging
5. Update documentation in docs/
```

### User Workflow

```
1. Read README.md
2. Build using scripts/build.sh or scripts/build.bat
3. Run examples/hello.cpp to verify
4. Write custom C++ programs
5. Compile and run with ./cpp_compiler
```

## File Dependencies

### Compilation Order

```
1. token.cpp (no dependencies)
2. lexer.cpp (depends on token.h)
3. ast.cpp (no dependencies)
4. parser.cpp (depends on token.h, ast.h)
5. interpreter.cpp (depends on ast.h)
6. main.cpp (depends on all above)
```

### Include Graph

```
main.cpp
  ├── compiler/lexer.h
  │     └── compiler/token.h
  ├── compiler/parser.h
  │     ├── compiler/token.h
  │     └── compiler/ast.h
  └── compiler/interpreter.h
        └── compiler/ast.h
```

## Size Statistics

### By Category

| Category | Files | Lines | Percentage |
|----------|-------|-------|------------|
| Compiler Core | 10 | 1,960 | 48% |
| Documentation | 7 | 2,000 | 49% |
| Examples | 6 | 150 | 4% |
| Build/Test Scripts | 4 | 195 | 5% |
| Configuration | 3 | 150 | 4% |
| **Total** | **30** | **~4,455** | **100%** |

### By File Type

| Type | Files | Lines |
|------|-------|-------|
| .cpp | 11 | 1,740 |
| .h | 5 | 470 |
| .md | 8 | 2,050 |
| .sh | 2 | 100 |
| .bat | 2 | 95 |
| Other | 2 | 50 |
| **Total** | **30** | **~4,505** |

## Navigation Guide

### For Users

1. **Start here:** README.md
2. **Build:** scripts/build.sh or scripts/build.bat
3. **Learn:** docs/QUICKSTART.md
4. **Examples:** examples/

### For Developers

1. **Architecture:** docs/ARCHITECTURE.md
2. **Code:** compiler/
3. **Build system:** Makefile, CMakeLists.txt
4. **Testing:** tests/, docs/TESTING_GUIDE.md

### For Contributors

1. **Overview:** docs/PROJECT_SUMMARY.md
2. **Structure:** docs/FILE_STRUCTURE.md
3. **Build:** docs/BUILD_GUIDE.md
4. **Test:** docs/TESTING_GUIDE.md

## Maintenance

### Adding New Features

1. Update compiler/ files
2. Add examples to examples/
3. Update docs/ARCHITECTURE.md
4. Add tests to tests/
5. Update README.md

### Adding Documentation

1. Create .md file in docs/
2. Link from README.md
3. Update this file (PROJECT_ORGANIZATION.md)

### Adding Examples

1. Create .cpp file in examples/
2. Add to test scripts in tests/
3. Document in docs/TESTING_GUIDE.md
4. Mention in README.md

## Best Practices

### File Naming

- Use lowercase with underscores: `file_name.cpp`
- Header files: `.h`
- Implementation files: `.cpp`
- Documentation: `.md`
- Scripts: `.sh` (Unix), `.bat` (Windows)

### Directory Naming

- Use lowercase: `compiler/`, `examples/`, `docs/`
- Plural for collections: `examples/`, `tests/`
- Singular for single purpose: `compiler/`

### Documentation

- One README.md at root
- Detailed docs in docs/
- Code comments in source files
- Examples are self-documenting

## Version Control

### Git Structure

```
.gitignore includes:
- Build artifacts (*.o, *.exe, cpp_compiler)
- IDE files (.vscode/, *.swp)
- OS files (.DS_Store, Thumbs.db)
- Build directories (build/, bin/, obj/)
```

### Recommended .gitignore

```
# Build artifacts
*.o
*.exe
cpp_compiler
a.out

# Build directories
build/
bin/
obj/

# IDE files
.vscode/
.idea/
*.swp
*.swo

# OS files
.DS_Store
Thumbs.db
```

## Summary

This project is organized into clear, logical sections:

✅ **compiler/** - Core implementation (1,960 lines)
✅ **examples/** - Working examples (150 lines)
✅ **docs/** - Comprehensive documentation (2,000 lines)
✅ **scripts/** - Build automation (95 lines)
✅ **tests/** - Test automation (100 lines)
✅ **Root files** - Entry point and configuration (200 lines)

**Total: 30 files, ~4,500 lines**

The organization follows software engineering best practices:
- Separation of concerns
- Modularity
- Clear documentation
- Automated building and testing
- Easy navigation
- Maintainable structure

This structure makes the project easy to understand, build, test, and extend.
