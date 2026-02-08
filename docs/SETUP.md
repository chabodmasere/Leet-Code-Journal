# Setup Guide

This guide will help you set up your environment for solving LeetCode problems in C++.

## Prerequisites

### Required
- **C++ Compiler** (g++, clang++, or MSVC)
- **C++17 or later** support
- **Git** for version control

### Recommended
- **Visual Studio Code** with C++ extensions
- **CMake** (optional, for larger projects)

---

## Installation

### Windows

#### Option 1: MinGW-w64 (Recommended)
1. Download MinGW-w64 from [winlibs.com](https://winlibs.com/)
2. Extract to `C:\mingw64`
3. Add to PATH: `C:\mingw64\bin`
4. Verify installation:
   ```cmd
   g++ --version
   ```

#### Option 2: Visual Studio
1. Install [Visual Studio Community](https://visualstudio.microsoft.com/)
2. Select "Desktop development with C++"
3. Use Developer Command Prompt

### macOS

#### Using Homebrew
```bash
# Install Homebrew if not already installed
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

# Install g++
brew install gcc

# Verify
g++ --version
```

#### Using Xcode
```bash
# Install Xcode Command Line Tools
xcode-select --install

# Verify
clang++ --version
```

### Linux (Ubuntu/Debian)

```bash
# Update package list
sudo apt update

# Install g++
sudo apt install g++ build-essential

# Verify
g++ --version
```

---

## IDE Setup

### Visual Studio Code (Recommended)

#### 1. Install VS Code
Download from [code.visualstudio.com](https://code.visualstudio.com/)

#### 2. Install Extensions
- **C/C++** (Microsoft)
- **C++ Intellisense** (austin)
- **Code Runner** (Jun Han)
- **Better Comments** (Aaron Bond)

#### 3. Configure C++ Settings

Create `.vscode/c_cpp_properties.json`:
```json
{
    "configurations": [
        {
            "name": "Win32",
            "includePath": [
                "${workspaceFolder}/**"
            ],
            "defines": [],
            "compilerPath": "C:/mingw64/bin/g++.exe",
            "cStandard": "c17",
            "cppStandard": "c++17",
            "intelliSenseMode": "gcc-x64"
        }
    ],
    "version": 4
}
```

Create `.vscode/tasks.json`:
```json
{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "Build C++",
            "type": "shell",
            "command": "g++",
            "args": [
                "-std=c++17",
                "-g",
                "${file}",
                "-o",
                "${fileDirname}/${fileBasenameNoExtension}"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            }
        }
    ]
}
```

---

## Compiling and Running

### Basic Compilation

```bash
# Compile
g++ -std=c++17 solution.cpp -o solution

# Run
./solution          # Linux/Mac
solution.exe        # Windows
```

### With Debugging Symbols

```bash
g++ -std=c++17 -g solution.cpp -o solution
```

### With Optimizations

```bash
g++ -std=c++17 -O2 solution.cpp -o solution
```

### Compile and Run Test

```bash
# Navigate to problem directory
cd problems/easy/001_two_sum

# Compile test file
g++ -std=c++17 test.cpp -o test

# Run tests
./test              # Linux/Mac
test.exe            # Windows
```

---

## Common Compilation Flags

| Flag | Purpose |
|------|---------|
| `-std=c++17` | Use C++17 standard |
| `-std=c++20` | Use C++20 standard |
| `-g` | Include debugging information |
| `-O2` | Optimization level 2 |
| `-O3` | Optimization level 3 |
| `-Wall` | Enable all warnings |
| `-Wextra` | Enable extra warnings |
| `-Werror` | Treat warnings as errors |
| `-fsanitize=address` | Enable address sanitizer |
| `-fsanitize=undefined` | Enable undefined behavior sanitizer |

### Recommended Compilation Command

```bash
g++ -std=c++17 -Wall -Wextra -g -O2 solution.cpp -o solution
```

---

## Testing Your Setup

### 1. Create a Test File

Create `test_setup.cpp`:
```cpp
#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    std::cout << "C++ Setup Test" << std::endl;
    
    // Test vector
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::cout << "Vector size: " << vec.size() << std::endl;
    
    // Test unordered_map
    std::unordered_map<int, int> map;
    map[1] = 100;
    std::cout << "Map value: " << map[1] << std::endl;
    
    std::cout << "✓ Setup successful!" << std::endl;
    return 0;
}
```

### 2. Compile and Run

```bash
g++ -std=c++17 test_setup.cpp -o test_setup
./test_setup
```

### Expected Output
```
C++ Setup Test
Vector size: 5
Map value: 100
✓ Setup successful!
```

---

## Troubleshooting

### Issue: "g++ is not recognized"
**Solution:** Add g++ to your system PATH
- Windows: Add `C:\mingw64\bin` to PATH
- Mac/Linux: Ensure g++ is installed

### Issue: "No such file or directory"
**Solution:** Check file paths and current directory
```bash
pwd           # Check current directory
ls            # List files
```

### Issue: Compilation errors with standard library
**Solution:** Ensure C++17 or later
```bash
g++ -std=c++17 file.cpp
```

### Issue: Permission denied (Linux/Mac)
**Solution:** Make file executable
```bash
chmod +x solution
./solution
```

---

## Using the Helper Scripts

### Create New Problem

```bash
# Windows
scripts\create_problem.bat 1 two-sum easy

# Linux/Mac
./scripts/create_problem.sh 1 two-sum easy
```

### Run All Tests

```bash
# Windows
scripts\run_tests.bat

# Linux/Mac
./scripts/run_tests.sh
```

---

## Best Practices

### 1. Use Version Control
```bash
git add .
git commit -m "Solved problem 1: Two Sum"
git push
```

### 2. Organize Your Code
- Keep each problem in its own directory
- Use meaningful variable names
- Add comments for complex logic

### 3. Test Thoroughly
- Test edge cases
- Test with large inputs
- Test with negative numbers
- Test with empty inputs

### 4. Optimize Gradually
1. Start with brute force
2. Identify bottlenecks
3. Optimize time complexity
4. Consider space complexity

---

## Additional Tools

### Online Compilers (for quick testing)
- [Compiler Explorer](https://godbolt.org/)
- [OnlineGDB](https://www.onlinegdb.com/)
- [Repl.it](https://replit.com/)

### Debugging Tools
- **gdb** (Linux/Mac)
- **lldb** (Mac)
- **Visual Studio Debugger** (Windows)

### Memory Leak Detection
```bash
# Valgrind (Linux/Mac)
valgrind --leak-check=full ./solution

# Address Sanitizer
g++ -fsanitize=address -g solution.cpp -o solution
./solution
```

---

## Next Steps

1. ✅ Verify your setup works
2. ✅ Try compiling the sample problem (001_two_sum)
3. ✅ Read the [patterns guide](../notes/patterns.md)
4. ✅ Start solving problems!

---

**Happy Coding! 🚀**
