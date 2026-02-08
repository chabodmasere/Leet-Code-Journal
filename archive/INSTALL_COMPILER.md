# How to Install a C++ Compiler and Complete Testing

This guide will help you install a C++ compiler on Windows and complete the testing of the C++ compiler project.

---

## Option 1: Install MinGW-w64 (Recommended - Easiest)

### Step 1: Download MinGW-w64

1. Visit: https://www.mingw-w64.org/downloads/
2. Or use direct link: https://github.com/niXman/mingw-builds-binaries/releases
3. Download: `x86_64-13.2.0-release-posix-seh-ucrt-rt_v11-rev1.7z`

### Step 2: Extract and Install

1. Extract the downloaded file to `C:\mingw64`
2. Add to PATH:
   - Open System Properties → Environment Variables
   - Edit "Path" variable
   - Add: `C:\mingw64\bin`
   - Click OK

### Step 3: Verify Installation

Open a NEW Command Prompt and run:
```cmd
g++ --version
```

Expected output:
```
g++ (x86_64-posix-seh-rev1, Built by MinGW-W64 project) 13.2.0
```

---

## Option 2: Install via winget (Windows Package Manager)

### Step 1: Install MinGW

Open PowerShell as Administrator and run:
```powershell
winget install -e --id=MSYS2.MSYS2
```

### Step 2: Configure MSYS2

1. Open MSYS2 terminal
2. Run:
```bash
pacman -Syu
pacman -S mingw-w64-x86_64-gcc
```

### Step 3: Add to PATH

Add `C:\msys64\mingw64\bin` to your PATH environment variable

### Step 4: Verify

```cmd
g++ --version
```

---

## Option 3: Install Visual Studio Build Tools (Microsoft)

### Step 1: Download

Visit: https://visualstudio.microsoft.com/downloads/
Download: "Build Tools for Visual Studio 2022"

### Step 2: Install

1. Run the installer
2. Select "Desktop development with C++"
3. Install

### Step 3: Use Developer Command Prompt

Open "Developer Command Prompt for VS 2022"

### Step 4: Modify Build Script

Edit `scripts/build.bat` to use `cl.exe` instead of `g++`:

```batch
@echo off
echo Building C++ Compiler...

cl /EHsc /std:c++17 /Fe:cpp_compiler.exe ^
   main.cpp ^
   compiler\token.cpp ^
   compiler\lexer.cpp ^
   compiler\ast.cpp ^
   compiler\parser.cpp ^
   compiler\interpreter.cpp

if %errorlevel% equ 0 (
    echo Build successful! Executable: cpp_compiler.exe
) else (
    echo Build failed!
)
```

---

## After Installing Compiler

### Step 1: Build the Compiler

Open Command Prompt in the project directory:

```cmd
cd "c:\Users\cmase\OneDrive\Desktop\GITHUB REPOS\Leet_Code_Journal"
scripts\build.bat
```

Expected output:
```
Building C++ Compiler...
Build successful! Executable: cpp_compiler.exe
```

### Step 2: Verify Build

Check that `cpp_compiler.exe` was created:
```cmd
dir cpp_compiler.exe
```

### Step 3: Run a Quick Test

```cmd
cpp_compiler.exe examples\hello.cpp
```

Expected output:
```
Hello, World!
```

### Step 4: Run Full Test Suite

```cmd
tests\run_all_tests.bat
```

Expected output:
```
=========================================
  C++ Compiler - Complete Test Suite
=========================================

=== Example Programs ===

Test 1: Hello World
Hello, World!
PASS

Test 2: Variables
x = 10
y = 20
sum = 30
PASS

Test 3: Conditionals
You are an adult
Grade: B
PASS

Test 4: Loops
While loop:
1 2 3 4 5
For loop:
1 2 3 4 5
Multiplication table:
1 2 3
2 4 6
3 6 9
PASS

Test 5: Functions
5 + 10 = 15
Factorial of 5 = 120
PASS

Test 6: Fibonacci
Fibonacci Sequence:
F(0) = 0
F(1) = 1
F(2) = 1
F(3) = 2
F(4) = 3
F(5) = 5
F(6) = 8
F(7) = 13
F(8) = 21
F(9) = 34
F(10) = 55
PASS

=========================================
  Test Results
=========================================
Passed: 6
Failed: 0
Total:  6

All tests passed!
```

---

## Troubleshooting

### Issue: "g++ is not recognized"

**Solution:**
1. Verify g++ is installed: `where g++`
2. Check PATH includes MinGW bin directory
3. Restart Command Prompt after adding to PATH
4. Try full path: `C:\mingw64\bin\g++ --version`

### Issue: "Permission denied"

**Solution:**
1. Run Command Prompt as Administrator
2. Check antivirus isn't blocking
3. Ensure you have write permissions in the directory

### Issue: Build fails with errors

**Solution:**
1. Check all source files are present
2. Verify C++17 support: `g++ --version` (should be 7.0+)
3. Try manual compilation:
```cmd
g++ -std=c++17 -Wall -Wextra -I. -o cpp_compiler main.cpp compiler/token.cpp compiler/lexer.cpp compiler/ast.cpp compiler/parser.cpp compiler/interpreter.cpp
```

### Issue: Examples don't run

**Solution:**
1. Verify executable was created: `dir cpp_compiler.exe`
2. Check example file exists: `dir examples\hello.cpp`
3. Try with full path: `cpp_compiler.exe examples\hello.cpp`
4. Check for runtime errors in output

---

## Quick Installation Commands

### For MinGW-w64 (Manual):
```cmd
REM 1. Download from https://github.com/niXman/mingw-builds-binaries/releases
REM 2. Extract to C:\mingw64
REM 3. Add C:\mingw64\bin to PATH
REM 4. Restart Command Prompt
g++ --version
```

### For MSYS2 (via winget):
```powershell
# Run as Administrator
winget install MSYS2.MSYS2
# Then in MSYS2 terminal:
pacman -Syu
pacman -S mingw-w64-x86_64-gcc
# Add C:\msys64\mingw64\bin to PATH
```

### For Visual Studio:
```cmd
REM Download from https://visualstudio.microsoft.com/downloads/
REM Install "Desktop development with C++"
REM Use "Developer Command Prompt for VS"
```

---

## Testing Checklist

After installing compiler, verify:

- [ ] Compiler installed: `g++ --version` works
- [ ] Build succeeds: `scripts\build.bat` completes
- [ ] Executable created: `cpp_compiler.exe` exists
- [ ] Hello World runs: `cpp_compiler.exe examples\hello.cpp`
- [ ] All tests pass: `tests\run_all_tests.bat`
- [ ] Lexer works: `cpp_compiler.exe -t examples\hello.cpp`
- [ ] Parser works: `cpp_compiler.exe -p examples\hello.cpp`

---

## Next Steps After Testing

Once all tests pass:

1. ✅ Compiler is fully functional
2. ✅ Try writing your own C++ programs
3. ✅ Experiment with the compiler features
4. ✅ Read the documentation in `docs/`
5. ✅ Extend the compiler with new features

---

## Support

If you encounter issues:

1. Check `docs/BUILD_GUIDE.md` for detailed build instructions
2. Review `docs/TESTING_GUIDE.md` for expected outputs
3. See `TEST_REPORT.md` for test results
4. Check compiler version supports C++17

---

## Summary

**Recommended Path:**
1. Install MinGW-w64 (easiest)
2. Add to PATH
3. Run `scripts\build.bat`
4. Run `tests\run_all_tests.bat`
5. Start using the compiler!

**Time Required:** 10-15 minutes

**Difficulty:** Easy (just download, extract, and add to PATH)

---

Good luck! Your C++ compiler is ready to build and test! 🚀
