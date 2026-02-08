# Quick Start Guide

Get up and running with the C++ Compiler in 5 minutes!

## Step 1: Verify Files

Make sure you have these directories:
```
✓ compiler/     (10 files)
✓ examples/     (6 files)
✓ main.cpp
✓ Build scripts (Makefile, CMakeLists.txt, build.bat, build.sh)
```

## Step 2: Build the Compiler

Choose your platform:

### Windows (with MinGW)
```cmd
build.bat
```

### Linux/macOS
```bash
chmod +x build.sh
./build.sh
```

### Using Make (Linux/macOS/WSL)
```bash
make
```

### Using CMake (Any platform)
```bash
mkdir build
cd build
cmake ..
cmake --build .
```

## Step 3: Test with Hello World

### Windows
```cmd
cpp_compiler.exe examples\hello.cpp
```

### Linux/macOS
```bash
./cpp_compiler examples/hello.cpp
```

**Expected Output:**
```
Hello, World!
```

## Step 4: Try More Examples

```bash
# Variables and arithmetic
./cpp_compiler examples/variables.cpp

# Conditionals
./cpp_compiler examples/conditionals.cpp

# Loops
./cpp_compiler examples/loops.cpp

# Functions
./cpp_compiler examples/functions.cpp

# Fibonacci
./cpp_compiler examples/fibonacci.cpp
```

## Step 5: Write Your Own Program

Create `myprogram.cpp`:
```cpp
int main() {
    int a = 10;
    int b = 20;
    int sum = a + b;
    
    cout << "The sum of " << a << " and " << b << " is " << sum << endl;
    
    return 0;
}
```

Run it:
```bash
./cpp_compiler myprogram.cpp
```

## Common Commands

### Show tokens (lexical analysis)
```bash
./cpp_compiler -t examples/hello.cpp
```

### Parse only (syntax check)
```bash
./cpp_compiler -p examples/hello.cpp
```

### Run program (default)
```bash
./cpp_compiler examples/hello.cpp
```

### Get help
```bash
./cpp_compiler -h
```

## Troubleshooting

### "g++ not found" (Windows)
1. Install MinGW-w64 from https://www.mingw-w64.org/
2. Add to PATH: `C:\mingw64\bin`
3. Restart terminal

### "Permission denied" (Linux/macOS)
```bash
chmod +x build.sh
chmod +x cpp_compiler
```

### Build errors
Make sure you have C++17 support:
```bash
g++ --version  # Should be 7.0 or higher
```

## What's Supported?

✅ Variables: `int`, `float`, `char`, `bool`
✅ Operators: `+`, `-`, `*`, `/`, `%`, `==`, `!=`, `<`, `>`, `<=`, `>=`, `&&`, `||`, `!`
✅ Control flow: `if`/`else`, `while`, `for`
✅ Functions: declarations, calls, recursion
✅ I/O: `cout`, `cin`, `endl`
✅ Comments: `//` and `/* */`

## Example Programs

### 1. Calculator
```cpp
int main() {
    int x = 15;
    int y = 4;
    
    cout << x << " + " << y << " = " << x + y << endl;
    cout << x << " - " << y << " = " << x - y << endl;
    cout << x << " * " << y << " = " << x * y << endl;
    cout << x << " / " << y << " = " << x / y << endl;
    cout << x << " % " << y << " = " << x % y << endl;
    
    return 0;
}
```

### 2. Factorial
```cpp
int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    for (int i = 1; i <= 10; i = i + 1) {
        cout << i << "! = " << factorial(i) << endl;
    }
    return 0;
}
```

### 3. Even/Odd Checker
```cpp
int main() {
    for (int i = 1; i <= 10; i = i + 1) {
        if (i % 2 == 0) {
            cout << i << " is even" << endl;
        } else {
            cout << i << " is odd" << endl;
        }
    }
    return 0;
}
```

### 4. Sum Calculator
```cpp
int main() {
    int sum = 0;
    int i = 1;
    
    while (i <= 100) {
        sum = sum + i;
        i = i + 1;
    }
    
    cout << "Sum of 1 to 100 = " << sum << endl;
    return 0;
}
```

## Next Steps

1. ✅ **Read README.md** - Full documentation
2. ✅ **Check BUILD_GUIDE.md** - Detailed build instructions
3. ✅ **Explore ARCHITECTURE.md** - How it works
4. ✅ **Review examples/** - More code samples
5. ✅ **Write your own programs!**

## Need Help?

- **Build issues**: See BUILD_GUIDE.md
- **Language features**: See README.md
- **How it works**: See ARCHITECTURE.md
- **File organization**: See FILE_STRUCTURE.md

## Success Checklist

- [ ] Compiler builds successfully
- [ ] `hello.cpp` runs and prints "Hello, World!"
- [ ] All examples run without errors
- [ ] You've written your first program
- [ ] You understand basic syntax

## You're Ready! 🎉

Start writing C++ programs and exploring compiler internals!

```bash
# Create a new program
echo 'int main() { cout << "I built a compiler!" << endl; return 0; }' > test.cpp

# Run it
./cpp_compiler test.cpp
```

Happy coding! 🚀
