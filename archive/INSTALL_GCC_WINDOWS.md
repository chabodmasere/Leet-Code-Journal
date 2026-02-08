# How to Install g++ on Windows (Simple Guide)

## Easiest Method: WinLibs (Recommended)

### Step 1: Download MinGW-w64

1. **Go to:** https://winlibs.com/
2. **Click:** "Download" under "Release versions"
3. **Choose:** `GCC 13.2.0 + MinGW-w64 11.0.1 (UCRT) - release 7`
4. **Download:** The `.zip` file (Win64 version)

### Step 2: Extract the Files

1. **Extract** the downloaded ZIP file
2. **Move** the extracted `mingw64` folder to `C:\`
3. **Final location:** `C:\mingw64\`

### Step 3: Add to System PATH

1. **Press** `Windows Key + R`
2. **Type:** `sysdm.cpl` and press Enter
3. **Click** "Advanced" tab
4. **Click** "Environment Variables" button
5. **Under "System variables"**, find and select "Path"
6. **Click** "Edit"
7. **Click** "New"
8. **Type:** `C:\mingw64\bin`
9. **Click** "OK" on all windows

### Step 4: Verify Installation

1. **Open** a NEW Command Prompt (important: must be new)
2. **Type:** `g++ --version`
3. **You should see:**
   ```
   g++ (MinGW-W64 x86_64-ucrt-posix-seh, built by Brecht Sanders) 13.2.0
   ```

### Step 5: Build Your Compiler!

```cmd
cd "c:\Users\cmase\OneDrive\Desktop\GITHUB REPOS\Leet_Code_Journal"
scripts\build.bat
```

---

## Alternative Method: MSYS2 (More Features)

### Step 1: Download MSYS2

1. **Go to:** https://www.msys2.org/
2. **Download:** `msys2-x86_64-latest.exe`
3. **Run** the installer

### Step 2: Install GCC

1. **Open** MSYS2 UCRT64 terminal (from Start menu)
2. **Run:**
   ```bash
   pacman -Syu
   ```
3. **Press** Enter when prompted
4. **Close** the terminal when it says to
5. **Open** MSYS2 UCRT64 again
6. **Run:**
   ```bash
   pacman -S mingw-w64-ucrt-x86_64-gcc
   ```
7. **Type** `Y` and press Enter

### Step 3: Add to PATH

1. **Add** `C:\msys64\ucrt64\bin` to your PATH (same steps as above)

### Step 4: Verify

```cmd
g++ --version
```

---

## Quick Visual Guide

### Adding to PATH (Visual Steps):

```
1. Windows Key + R
   ┌─────────────────────┐
   │ Run                 │
   │ sysdm.cpl          │
   └─────────────────────┘

2. System Properties → Advanced → Environment Variables
   ┌─────────────────────────────────┐
   │ System variables:               │
   │ ┌─────────────────────────────┐ │
   │ │ Path                        │ │
   │ └─────────────────────────────┘ │
   │         [Edit]                  │
   └─────────────────────────────────┘

3. Edit → New → Add: C:\mingw64\bin
   ┌─────────────────────────────────┐
   │ C:\Windows\System32             │
   │ C:\Windows                      │
   │ C:\mingw64\bin          ← NEW!  │
   └─────────────────────────────────┘

4. OK → OK → OK (close all windows)

5. Open NEW Command Prompt
   cmd → g++ --version ✓
```

---

## Troubleshooting

### Problem: "g++ is not recognized"

**Solution 1:** Did you open a NEW Command Prompt?
- Close all Command Prompts
- Open a fresh one
- Try again

**Solution 2:** Check PATH was added correctly
```cmd
echo %PATH%
```
Should contain `C:\mingw64\bin`

**Solution 3:** Verify files exist
```cmd
dir C:\mingw64\bin\g++.exe
```
Should show the file

### Problem: "Access denied" when extracting

**Solution:** Extract to your Downloads folder first, then move to C:\

### Problem: Can't edit System PATH

**Solution:** You need Administrator rights
- Right-click Command Prompt
- Choose "Run as Administrator"
- Or ask your system administrator

---

## After Installation - Build Your Compiler!

### 1. Open Command Prompt

```cmd
cd "c:\Users\cmase\OneDrive\Desktop\GITHUB REPOS\Leet_Code_Journal"
```

### 2. Build

```cmd
scripts\build.bat
```

**Expected output:**
```
Building C++ Compiler...
Build successful! Executable: cpp_compiler.exe
```

### 3. Test

```cmd
cpp_compiler.exe examples\hello.cpp
```

**Expected output:**
```
Hello, World!
```

### 4. Run All Tests

```cmd
tests\run_all_tests.bat
```

**Expected output:**
```
All tests passed! ✓
```

---

## Summary - 5 Minute Installation

1. **Download:** https://winlibs.com/ (get the ZIP file)
2. **Extract:** to `C:\mingw64`
3. **Add to PATH:** `C:\mingw64\bin`
4. **Verify:** Open NEW cmd → `g++ --version`
5. **Build:** `scripts\build.bat`
6. **Done!** 🎉

---

## Need Help?

If you get stuck:
1. Make sure you opened a NEW Command Prompt after adding to PATH
2. Check `C:\mingw64\bin\g++.exe` exists
3. Verify PATH contains `C:\mingw64\bin`
4. Try restarting your computer

---

## Direct Download Links

**WinLibs (Recommended):**
https://github.com/brechtsanders/winlibs_mingw/releases/latest

**MSYS2:**
https://github.com/msys2/msys2-installer/releases/latest

---

Good luck! You're just 5 minutes away from running your C++ compiler! 🚀
