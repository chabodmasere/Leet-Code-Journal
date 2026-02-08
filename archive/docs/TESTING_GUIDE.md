# Comprehensive Testing Guide

This guide provides expected outputs and testing procedures for the C++ compiler.

## Prerequisites

Before testing, ensure you have:
- ✅ C++17 compatible compiler installed (g++, clang++, or MSVC)
- ✅ Built the cpp_compiler executable
- ✅ All example files in the `examples/` directory

## Build Verification

### Step 1: Build the Compiler

**Using build script (Windows):**
```cmd
build.bat
```

**Expected Output:**
```
Building C++ Compiler...
Build successful! Executable: cpp_compiler.exe

Usage: cpp_compiler.exe [options] <source_file>
Example: cpp_compiler.exe examples/hello.cpp
```

**Using build script (Linux/macOS):**
```bash
chmod +x build.sh
./build.sh
```

**Expected Output:**
```
Building C++ Compiler...
Using compiler: g++
Build successful! Executable: cpp_compiler

Usage: ./cpp_compiler [options] <source_file>
Example: ./cpp_compiler examples/hello.cpp

Run './cpp_compiler -h' for more options
```

**Verification:**
- ✅ No compilation errors
- ✅ Executable file created (cpp_compiler or cpp_compiler.exe)
- ✅ File size > 100KB

---

## Example Program Testing

### Test 1: Hello World (examples/hello.cpp)

**Command:**
```bash
./cpp_compiler examples/hello.cpp
```

**Expected Output:**
```
Hello, World!
```

**Verification:**
- ✅ Prints "Hello, World!"
- ✅ Followed by newline
- ✅ No errors
- ✅ Exit code 0

---

### Test 2: Variables (examples/variables.cpp)

**Command:**
```bash
./cpp_compiler examples/variables.cpp
```

**Expected Output:**
```
x = 10
y = 20
sum = 30
```

**Verification:**
- ✅ Correct variable values printed
- ✅ Arithmetic operation (10 + 20 = 30) works
- ✅ Multiple cout statements execute in order
- ✅ No errors

---

### Test 3: Conditionals (examples/conditionals.cpp)

**Command:**
```bash
./cpp_compiler examples/conditionals.cpp
```

**Expected Output:**
```
You are an adult
Grade: B
```

**Verification:**
- ✅ First if statement (age >= 18) executes correctly
- ✅ Else-if chain works (score = 85, so Grade: B)
- ✅ Comparison operators work (>=)
- ✅ No errors

---

### Test 4: Loops (examples/loops.cpp)

**Command:**
```bash
./cpp_compiler examples/loops.cpp
```

**Expected Output:**
```
While loop:
1 2 3 4 5 
For loop:
1 2 3 4 5 
Multiplication table:
1 2 3 
2 4 6 
3 6 9 
```

**Verification:**
- ✅ While loop executes 5 times
- ✅ For loop executes 5 times
- ✅ Nested loops work correctly
- ✅ Loop variables increment properly
- ✅ Multiplication calculations correct (1×1=1, 1×2=2, ..., 3×3=9)
- ✅ No errors

---

### Test 5: Functions (examples/functions.cpp)

**Command:**
```bash
./cpp_compiler examples/functions.cpp
```

**Expected Output:**
```
5 + 10 = 15
Factorial of 5 = 120
```

**Verification:**
- ✅ Function `add(5, 10)` returns 15
- ✅ Recursive function `factorial(5)` returns 120
- ✅ Function calls work correctly
- ✅ Return values propagate properly
- ✅ Recursion works (5! = 5×4×3×2×1 = 120)
- ✅ No errors

---

### Test 6: Fibonacci (examples/fibonacci.cpp)

**Command:**
```bash
./cpp_compiler examples/fibonacci.cpp
```

**Expected Output:**
```
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
```

**Verification:**
- ✅ Fibonacci sequence is correct (each number is sum of previous two)
- ✅ Recursive function works for multiple calls
- ✅ Loop with function calls works
- ✅ All 11 values (0-10) are correct
- ✅ No errors

---

## Lexer Testing

### Test 7: Token Display

**Command:**
```bash
./cpp_compiler -t examples/hello.cpp
```

**Expected Output:**
```
=== TOKENS ===
Token(INT, "int", 4:1)
Token(IDENTIFIER, "main", 4:5)
Token(LPAREN, "(", 4:9)
Token(RPAREN, ")", 4:10)
Token(LBRACE, "{", 4:12)
Token(COUT, "cout", 5:5)
Token(LSHIFT, "<<", 5:10)
Token(STRING, "Hello, World!", 5:13)
Token(LSHIFT, "<<", 5:29)
Token(ENDL, "endl", 5:32)
Token(SEMICOLON, ";", 5:36)
Token(RETURN, "return", 6:5)
Token(INTEGER, "0", 6:12)
Token(SEMICOLON, ";", 6:13)
Token(RBRACE, "}", 7:1)
Token(END_OF_FILE, "", 7:2)
```

**Verification:**
- ✅ All tokens identified correctly
- ✅ Token types match expected values
- ✅ Line and column numbers are accurate
- ✅ Keywords recognized (int, return)
- ✅ Operators recognized (<<)
- ✅ String literals captured
- ✅ EOF token at end

---

## Parser Testing

### Test 8: Parse Verification

**Command:**
```bash
./cpp_compiler -p examples/hello.cpp
```

**Expected Output:**
```
=== PARSING SUCCESSFUL ===
Functions: 1
Global statements: 0
```

**Verification:**
- ✅ Parsing completes without errors
- ✅ Correct function count (1 = main)
- ✅ Correct global statement count (0)
- ✅ No syntax errors reported

**Test with more complex file:**
```bash
./cpp_compiler -p examples/functions.cpp
```

**Expected Output:**
```
=== PARSING SUCCESSFUL ===
Functions: 3
Global statements: 0
```

**Verification:**
- ✅ All 3 functions detected (add, factorial, main)
- ✅ No parsing errors

---

## Error Handling Testing

### Test 9: Syntax Error

**Create test file `test_syntax_error.cpp`:**
```cpp
int main() {
    int x = 10
    return 0;
}
```

**Command:**
```bash
./cpp_compiler test_syntax_error.cpp
```

**Expected Output:**
```
Parse Error: Parse error at line 3, column 5: Expected ';' after variable declaration. Got RETURN
```

**Verification:**
- ✅ Error detected
- ✅ Line number reported (3)
- ✅ Column number reported
- ✅ Clear error message
- ✅ Non-zero exit code

---

### Test 10: Undefined Variable

**Create test file `test_undefined_var.cpp`:**
```cpp
int main() {
    cout << x << endl;
    return 0;
}
```

**Command:**
```bash
./cpp_compiler test_undefined_var.cpp
```

**Expected Output:**
```
Runtime Error: Undefined variable: x
```

**Verification:**
- ✅ Runtime error detected
- ✅ Variable name reported (x)
- ✅ Clear error message
- ✅ Non-zero exit code

---

### Test 11: Division by Zero

**Create test file `test_division_zero.cpp`:**
```cpp
int main() {
    int x = 10;
    int y = 0;
    int z = x / y;
    cout << z << endl;
    return 0;
}
```

**Command:**
```bash
./cpp_compiler test_division_zero.cpp
```

**Expected Output:**
```
Runtime Error: Division by zero
```

**Verification:**
- ✅ Runtime error detected
- ✅ Clear error message
- ✅ Non-zero exit code

---

### Test 12: Undefined Function

**Create test file `test_undefined_func.cpp`:**
```cpp
int main() {
    int result = unknownFunction(5);
    return 0;
}
```

**Command:**
```bash
./cpp_compiler test_undefined_func.cpp
```

**Expected Output:**
```
Runtime Error: Undefined function: unknownFunction
```

**Verification:**
- ✅ Runtime error detected
- ✅ Function name reported
- ✅ Clear error message
- ✅ Non-zero exit code

---

## Edge Case Testing

### Test 13: Deep Recursion

**Create test file `test_deep_recursion.cpp`:**
```cpp
int countdown(int n) {
    if (n <= 0) {
        return 0;
    }
    return countdown(n - 1);
}

int main() {
    int result = countdown(100);
    cout << "Done: " << result << endl;
    return 0;
}
```

**Command:**
```bash
./cpp_compiler test_deep_recursion.cpp
```

**Expected Output:**
```
Done: 0
```

**Verification:**
- ✅ Deep recursion (100 levels) works
- ✅ No stack overflow
- ✅ Correct result

---

### Test 14: Complex Expressions

**Create test file `test_complex_expr.cpp`:**
```cpp
int main() {
    int result = (5 + 3) * 2 - 10 / 2;
    cout << "Result: " << result << endl;
    return 0;
}
```

**Command:**
```bash
./cpp_compiler test_complex_expr.cpp
```

**Expected Output:**
```
Result: 11
```

**Calculation:** (5 + 3) * 2 - 10 / 2 = 8 * 2 - 5 = 16 - 5 = 11

**Verification:**
- ✅ Operator precedence correct
- ✅ Parentheses work
- ✅ Multiple operations in one expression
- ✅ Correct result (11)

---

### Test 15: Nested Control Flow

**Create test file `test_nested_control.cpp`:**
```cpp
int main() {
    for (int i = 1; i <= 3; i = i + 1) {
        if (i % 2 == 0) {
            cout << i << " is even" << endl;
        } else {
            cout << i << " is odd" << endl;
        }
    }
    return 0;
}
```

**Command:**
```bash
./cpp_compiler test_nested_control.cpp
```

**Expected Output:**
```
1 is odd
2 is even
3 is odd
```

**Verification:**
- ✅ For loop works
- ✅ If-else inside loop works
- ✅ Modulo operator works
- ✅ Correct output for each iteration

---

## Performance Testing

### Test 16: Large Loop

**Create test file `test_large_loop.cpp`:**
```cpp
int main() {
    int sum = 0;
    for (int i = 1; i <= 10000; i = i + 1) {
        sum = sum + i;
    }
    cout << "Sum: " << sum << endl;
    return 0;
}
```

**Command:**
```bash
time ./cpp_compiler test_large_loop.cpp
```

**Expected Output:**
```
Sum: 50005000
```

**Verification:**
- ✅ Completes in reasonable time (< 5 seconds)
- ✅ Correct sum (1+2+...+10000 = 50,005,000)
- ✅ No performance issues

---

## Complete Test Suite Summary

### Quick Test Script

**Create `run_all_tests.sh` (Linux/macOS):**
```bash
#!/bin/bash

echo "=== Running All Tests ==="
echo ""

echo "Test 1: Hello World"
./cpp_compiler examples/hello.cpp
echo ""

echo "Test 2: Variables"
./cpp_compiler examples/variables.cpp
echo ""

echo "Test 3: Conditionals"
./cpp_compiler examples/conditionals.cpp
echo ""

echo "Test 4: Loops"
./cpp_compiler examples/loops.cpp
echo ""

echo "Test 5: Functions"
./cpp_compiler examples/functions.cpp
echo ""

echo "Test 6: Fibonacci"
./cpp_compiler examples/fibonacci.cpp
echo ""

echo "=== All Tests Complete ==="
```

**Create `run_all_tests.bat` (Windows):**
```batch
@echo off
echo === Running All Tests ===
echo.

echo Test 1: Hello World
cpp_compiler.exe examples\hello.cpp
echo.

echo Test 2: Variables
cpp_compiler.exe examples\variables.cpp
echo.

echo Test 3: Conditionals
cpp_compiler.exe examples\conditionals.cpp
echo.

echo Test 4: Loops
cpp_compiler.exe examples\loops.cpp
echo.

echo Test 5: Functions
cpp_compiler.exe examples\functions.cpp
echo.

echo Test 6: Fibonacci
cpp_compiler.exe examples\fibonacci.cpp
echo.

echo === All Tests Complete ===
pause
```

---

## Test Checklist

Use this checklist to verify all tests:

### Build Tests
- [ ] Compiler builds without errors
- [ ] Executable created successfully
- [ ] No warnings during compilation

### Example Programs
- [ ] hello.cpp runs and outputs "Hello, World!"
- [ ] variables.cpp shows correct arithmetic
- [ ] conditionals.cpp shows correct branching
- [ ] loops.cpp shows correct iteration
- [ ] functions.cpp shows correct function calls
- [ ] fibonacci.cpp shows correct sequence

### Lexer Tests
- [ ] Tokens displayed with -t flag
- [ ] All token types recognized
- [ ] Line/column numbers accurate

### Parser Tests
- [ ] Parsing succeeds with -p flag
- [ ] Function count correct
- [ ] No syntax errors on valid code

### Error Handling
- [ ] Syntax errors detected and reported
- [ ] Runtime errors detected and reported
- [ ] Undefined variables caught
- [ ] Division by zero caught
- [ ] Undefined functions caught

### Edge Cases
- [ ] Deep recursion works
- [ ] Complex expressions evaluate correctly
- [ ] Nested control flow works
- [ ] Large loops complete successfully

### Performance
- [ ] Programs execute in reasonable time
- [ ] No memory leaks (if tested with valgrind)
- [ ] No crashes or hangs

---

## Troubleshooting Test Failures

### If a test fails:

1. **Check the error message** - Does it indicate syntax or runtime error?
2. **Verify the input file** - Is the example file correct?
3. **Check compiler version** - Is C++17 supported?
4. **Review the code** - Look at the relevant compiler component
5. **Add debug output** - Modify interpreter to print intermediate values
6. **Test incrementally** - Start with simpler programs

### Common Issues:

**Issue:** "Undefined variable" on valid code
- **Cause:** Variable not declared before use
- **Fix:** Check variable declaration order

**Issue:** Wrong arithmetic result
- **Cause:** Operator precedence or type conversion
- **Fix:** Review BinaryOp evaluation in interpreter

**Issue:** Infinite loop
- **Cause:** Loop condition never becomes false
- **Fix:** Check loop increment/decrement

**Issue:** Segmentation fault
- **Cause:** Null pointer or invalid memory access
- **Fix:** Check smart pointer usage in AST

---

## Success Criteria

All tests pass when:
- ✅ All 6 example programs produce correct output
- ✅ Lexer correctly tokenizes all examples
- ✅ Parser successfully parses all examples
- ✅ Error handling catches all error cases
- ✅ Edge cases work correctly
- ✅ Performance is acceptable

**Expected Success Rate:** 100% (all tests should pass)

---

## Next Steps After Testing

Once all tests pass:
1. ✅ Compiler is fully functional
2. ✅ Ready for use with custom programs
3. ✅ Can be extended with new features
4. ✅ Can be used for educational purposes

Congratulations! You have a working C++ compiler! 🎉
