# C++ Compiler Setup for Windows

You need a C++ compiler to compile and run your LeetCode solutions. Here are your options:

## Option 1: MinGW-w64 (Recommended - Lightweight)

### Quick Install:
1. Download MSYS2 from: https://www.msys2.org/
2. Run the installer and follow the prompts
3. After installation, open "MSYS2 MSYS" from Start Menu
4. Run these commands:
   ```bash
   pacman -Syu
   pacman -S mingw-w64-x86_64-gcc
   ```
5. Add to PATH: `C:\msys64\mingw64\bin`
   - Search "Environment Variables" in Windows
   - Edit "Path" variable
   - Add new entry: `C:\msys64\mingw64\bin`
6. Restart VSCode

### Verify Installation:
```bash
g++ --version
```

## Option 2: Visual Studio Build Tools (Microsoft)

### Install:
1. Download from: https://visualstudio.microsoft.com/downloads/
2. Select "Build Tools for Visual Studio 2022"
3. In installer, select "Desktop development with C++"
4. Install (requires ~7GB)

### Verify Installation:
Open "Developer Command Prompt for VS" and run:
```bash
cl
```

## Option 3: Online Compilers (No Installation)

If you don't want to install anything locally, use online compilers:
- **Compiler Explorer**: https://godbolt.org/
- **OnlineGDB**: https://www.onlinegdb.com/online_c++_compiler
- **Replit**: https://replit.com/languages/cpp

Just copy your code from the `.cpp` files and paste it there.

## After Installing Compiler

### Update VSCode Configuration:

1. If you installed MinGW, update `.vscode/c_cpp_properties.json`:
   ```json
   "compilerPath": "C:/msys64/mingw64/bin/g++.exe"
   ```

2. If you installed Visual Studio, update to:
   ```json
   "compilerPath": "C:/Program Files/Microsoft Visual Studio/2022/BuildTools/VC/Tools/MSVC/14.xx.xxxxx/bin/Hostx64/x64/cl.exe"
   ```

### Compile Your First Problem:

```bash
# Navigate to your repository
cd "C:\Users\cmase\OneDrive\Desktop\GITHUB REPOS\Leet_Code_Journal"

# Compile Two Sum
g++ -std=c++17 problems/easy/001_two_sum.cpp -o two_sum

# Run it
two_sum.exe
```

## Troubleshooting

### "g++ is not recognized"
- Make sure you added the compiler to your PATH
- Restart your terminal/VSCode after adding to PATH

### Red underlines in VSCode still showing
- Reload VSCode: Press `Ctrl+Shift+P` → "Reload Window"
- Or close and reopen VSCode

### Need help?
Check the existing `INSTALL_GCC_WINDOWS.md` file in the archive folder for more detailed instructions.

---

**Note:** The red underlines you're seeing are just VSCode warnings because it can't find the compiler. Your code is correct! Once you install a compiler and configure VSCode, the warnings will disappear.
