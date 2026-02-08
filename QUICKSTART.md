# Quick Start Guide

Get started with your LeetCode journal in 5 minutes!

## 📋 Prerequisites

- C++ compiler (g++, clang++, or MSVC)
- Git (optional, for version control)

## 🚀 Quick Setup

### 1. Verify Your Compiler

```bash
g++ --version
```

If not installed, see [SETUP.md](docs/SETUP.md) for installation instructions.

### 2. Test the Sample Problem

```bash
# Navigate to the sample problem
cd problems/easy/001_two_sum

# Compile and run tests
g++ -std=c++17 test.cpp -o test
./test          # Linux/Mac
test.exe        # Windows
```

Expected output:
```
========================================
Testing Two Sum Solution
========================================

Test 1: Basic case
Input: [2, 7, 11, 15], target = 9
Output: [0, 1]
✓ PASSED

...

All tests completed!
========================================
```

## 📝 Solving Your First Problem

### Method 1: Using the Helper Script (Recommended)

```bash
# Windows
scripts\create_problem.bat 1 two-sum easy

# Linux/Mac (when available)
./scripts/create_problem.sh 1 two-sum easy
```

### Method 2: Manual Setup

1. **Create directory:**
   ```bash
   mkdir -p problems/easy/002_add_two_numbers
   cd problems/easy/002_add_two_numbers
   ```

2. **Create files:**
   - `README.md` - Problem description and approach
   - `solution.cpp` - Your solution
   - `test.cpp` - Test cases

3. **Use templates from** `problems/easy/001_two_sum/` as reference

## 🎯 Workflow

### 1. Choose a Problem
Visit [LeetCode](https://leetcode.com/problemset/all/) and pick a problem

### 2. Create Problem Structure
```bash
scripts\create_problem.bat <number> <name> <difficulty>
```

### 3. Solve the Problem
Edit `solution.cpp` with your solution

### 4. Add Tests
Edit `test.cpp` with test cases

### 5. Run Tests
```bash
cd problems/<difficulty>/<number>_<name>
g++ -std=c++17 test.cpp -o test
./test
```

### 6. Document Your Solution
Update `README.md` with:
- Problem description
- Your approach
- Complexity analysis
- Key insights

### 7. Update Progress
Update the main `README.md` progress tracker

## 📚 Essential Resources

### In This Repository
- [Setup Guide](docs/SETUP.md) - Detailed environment setup
- [Contributing Guide](docs/CONTRIBUTING.md) - How to add problems
- [Patterns Guide](notes/patterns.md) - Common problem-solving patterns
- [Time Complexity Guide](notes/time_complexity.md) - Big O reference

### Templates
- [ListNode.h](templates/data_structures/ListNode.h) - Linked list operations
- [TreeNode.h](templates/data_structures/TreeNode.h) - Binary tree operations

### Sample Problem
- [001_two_sum](problems/easy/001_two_sum/) - Complete example

## 💡 Quick Tips

### Compilation
```bash
# Basic
g++ -std=c++17 solution.cpp -o solution

# With warnings
g++ -std=c++17 -Wall -Wextra solution.cpp -o solution

# With debugging
g++ -std=c++17 -g solution.cpp -o solution

# Optimized
g++ -std=c++17 -O2 solution.cpp -o solution
```

### Common Includes
```cpp
#include <vector>           // Dynamic arrays
#include <unordered_map>    // Hash tables
#include <unordered_set>    // Hash sets
#include <string>           // Strings
#include <algorithm>        // Sorting, searching
#include <queue>            // Queue, priority_queue
#include <stack>            // Stack
#include <iostream>         // Input/output
```

### Problem-Solving Strategy
1. **Understand** - Read problem carefully
2. **Examples** - Work through examples
3. **Brute Force** - Start with simple solution
4. **Optimize** - Improve time/space complexity
5. **Code** - Implement solution
6. **Test** - Run test cases
7. **Review** - Analyze and document

## 🎓 Learning Path

### Week 1: Arrays & Strings
- Two Sum
- Valid Palindrome
- Best Time to Buy and Sell Stock
- Contains Duplicate
- Maximum Subarray

### Week 2: Linked Lists
- Reverse Linked List
- Merge Two Sorted Lists
- Linked List Cycle
- Remove Nth Node From End

### Week 3: Trees
- Maximum Depth of Binary Tree
- Invert Binary Tree
- Symmetric Tree
- Binary Tree Level Order Traversal

### Week 4: Hash Tables & Sets
- Group Anagrams
- Longest Consecutive Sequence
- Valid Anagram
- Intersection of Two Arrays

## 🔧 Troubleshooting

### "g++ not found"
Install a C++ compiler. See [SETUP.md](docs/SETUP.md)

### "Permission denied"
```bash
chmod +x test    # Make executable (Linux/Mac)
```

### Compilation errors
- Check C++ standard: `-std=c++17`
- Verify all includes are present
- Check for syntax errors

### Test failures
- Review your logic
- Check edge cases
- Add debug print statements

## 📊 Track Your Progress

Update `README.md` after each problem:

```markdown
| Difficulty | Solved | Total | Percentage |
|------------|--------|-------|------------|
| 🟢 Easy    | 5      | ~600  | 0.83%      |
| 🟡 Medium  | 2      | ~1300 | 0.15%      |
| 🔴 Hard    | 0      | ~600  | 0%         |
```

## 🎯 Daily Goals

- **Beginner:** 1 easy problem per day
- **Intermediate:** 1 medium problem per day
- **Advanced:** 1 hard problem per day
- **Interview Prep:** 2-3 problems per day

## 📞 Need Help?

- Check [SETUP.md](docs/SETUP.md) for environment issues
- Review [CONTRIBUTING.md](docs/CONTRIBUTING.md) for workflow
- Study [patterns.md](notes/patterns.md) for problem-solving techniques
- Reference [time_complexity.md](notes/time_complexity.md) for Big O

## ✅ Checklist

Before you start:
- [ ] C++ compiler installed and working
- [ ] Tested sample problem (001_two_sum)
- [ ] Read the patterns guide
- [ ] Understand the workflow
- [ ] Ready to solve problems!

---

**You're all set! Start solving problems and track your progress! 🚀**

*Happy Coding!*
