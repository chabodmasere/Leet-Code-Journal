# Build Guide for C++ Compiler

This guide provides detailed instructions for building the C++ compiler on different platforms.

## Prerequisites

You need a C++17 compatible compiler. Here are the options for different platforms:

### Windows

**Option 1: MinGW-w64 (Recommended for Windows)**
1. Download from: https://www.mingw-w64.org/
2. Or install via MSYS2: https://www.msys2.org/
3. Add to PATH: `C:\msys64\mingw64\bin` (or your installation path)

**Option 2: Microsoft Visual Studio**
1. Download Visual Studio Community (free): https://visualstudio.microsoft.com/
2. Install "Desktop development with C++" workload
3. Use Developer Command Prompt for VS

**Option 3: Clang/LLVM**
1. Download from: https://releases.llvm.org/
2. Install and add to PATH

### Linux

Most Linux distributions come with g++ pre-installed.

```bash
# Ubuntu/Debian
sudo apt-get update
sudo apt-get install build-essential

# Fedora/RHEL
sudo dnf install gcc-c++

# Arch Linux
sudo pacman -S gcc
```

### macOS

```bash
# Install Xcode Command Line Tools
xcode-select --install

# Or install via Homebrew
brew install gcc
```

## Building the Compiler

### Method 1: Using Build Scripts (Easiest)

#### Windows
```cmd
build.bat
```

#### Linux/macOS
```bash
chmod +x build.sh
./build.sh
```

### Method 2: Using Makefile (Linux/macOS/WSL)

```bash
# Build
make

# Clean
make clean

# Build and run example
make run
```

### Method 3: Using CMake (Cross-platform)

```bash
# Create build directory
mkdir build
cd build

# Configure
cmake ..

# Build
cmake --build .

# On Windows with Visual Studio
cmake --build . --config Release
```

### Method 4: Manual Compilation

#### Using g++ (MinGW on Windows, g++ on Linux/macOS)

```bash
g++ -std=c++17 -Wall -Wextra -I. -o cpp_compiler main.cpp compiler/token.cpp compiler/lexer.cpp compiler/ast.cpp compiler/parser.cpp compiler/interpreter.cpp
```

#### Using clang++

```bash
clang++ -std=c++17 -Wall -Wextra -I. -o cpp_compiler main.cpp compiler/token.cpp compiler/lexer.cpp compiler/ast.cpp compiler/parser.cpp compiler/interpreter.cpp
```

#### Using MSVC (Visual Studio Developer Command Prompt)

```cmd
cl /EHsc /std:c++17 /I. main.cpp compiler/token.cpp compiler/lexer.cpp compiler/ast.cpp compiler/parser.cpp compiler/interpreter.cpp /Fe:cpp_compiler.exe
```

## Verifying the Build

After building, test the compiler with an example:

### Windows
```cmd
cpp_compiler.exe examples/hello.cpp
```

### Linux/macOS
```bash
./cpp_compiler examples/hello.cpp
```

Expected output:
```
Hello, World!
```

## Troubleshooting

### Issue: "g++ is not recognized"

**Solution**: Install MinGW-w64 or add g++ to your PATH.

1. Download MinGW-w64
2. Install to `C:\mingw64`
3. Add `C:\mingw64\bin` to System PATH
4. Restart terminal/command prompt

### Issue: "No such file or directory" errors

**Solution**: Make sure you're in the project root directory where `main.cpp` is located.

```bash
# Check current directory
pwd  # Linux/macOS
cd   # Windows

# List files
ls   # Linux/macOS
dir  # Windows
```

### Issue: C++17 not supported

**Solution**: Update your compiler.

```bash
# Check g++ version (should be 7.0 or higher)
g++ --version

# Check clang version (should be 5.0 or higher)
clang++ --version
```

### Issue: Linking errors

**Solution**: Make sure all source files are included in the compilation command.

### Issue: "variant" or "optional" not found

**Solution**: Your compiler doesn't support C++17. Update to:
- g++ 7.0 or higher
- clang++ 5.0 or higher
- MSVC 2017 or higher

## Platform-Specific Notes

### Windows with MinGW

If you installed MinGW via MSYS2:

```bash
# Open MSYS2 MinGW 64-bit terminal
pacman -S mingw-w64-x86_64-gcc
cd /c/Users/YourName/path/to/project
g++ -std=c++17 -Wall -Wextra -I. -o cpp_compiler.exe main.cpp compiler/*.cpp
```

### Windows with Visual Studio

```cmd
# Open "Developer Command Prompt for VS"
cd C:\path\to\project
cl /EHsc /std:c++17 /I. main.cpp compiler\token.cpp compiler\lexer.cpp compiler\ast.cpp compiler\parser.cpp compiler\interpreter.cpp /Fe:cpp_compiler.exe
```

### macOS with Homebrew GCC

```bash
# If using Homebrew GCC instead of Apple Clang
g++-13 -std=c++17 -Wall -Wextra -I. -o cpp_compiler main.cpp compiler/*.cpp
```

### Linux

Standard build should work:

```bash
g++ -std=c++17 -Wall -Wextra -I. -o cpp_compiler main.cpp compiler/*.cpp
```

## Quick Start (After Building)

1. **Build the compiler** (choose one method above)

2. **Run an example**:
   ```bash
   ./cpp_compiler examples/hello.cpp
   ```

3. **Create your own program**:
   ```cpp
   // myprogram.cpp
   int main() {
       cout << "My first program!" << endl;
       return 0;
   }
   ```

4. **Compile and run**:
   ```bash
   ./cpp_compiler myprogram.cpp
   ```

## Advanced Build Options

### Debug Build

```bash
g++ -std=c++17 -g -Wall -Wextra -I. -o cpp_compiler_debug main.cpp compiler/*.cpp
```

### Optimized Build

```bash
g++ -std=c++17 -O3 -Wall -Wextra -I. -o cpp_compiler main.cpp compiler/*.cpp
```

### Static Linking (for portability)

```bash
g++ -std=c++17 -static -Wall -Wextra -I. -o cpp_compiler main.cpp compiler/*.cpp
```

## Getting Help

If you encounter issues:

1. Check that you're using C++17 compatible compiler
2. Verify all source files are present
3. Make sure you're in the correct directory
4. Check compiler version: `g++ --version` or `clang++ --version`
5. Try the manual compilation method to see detailed error messages

## Next Steps

After successfully building:

1. Read [README.md](README.md) for usage instructions
2. Try all examples in the `examples/` directory
3. Write your own C++ programs
4. Explore the compiler source code to understand how it works
