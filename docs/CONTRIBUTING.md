# Contributing Guide

How to add new problems and maintain this LeetCode journal.

## Table of Contents
1. [Adding a New Problem](#adding-a-new-problem)
2. [File Structure](#file-structure)
3. [Coding Standards](#coding-standards)
4. [Documentation Standards](#documentation-standards)
5. [Testing Guidelines](#testing-guidelines)

---

## Adding a New Problem

### Method 1: Using the Helper Script (Recommended)

```bash
# Windows
scripts\create_problem.bat <number> <name> <difficulty>

# Example
scripts\create_problem.bat 15 3sum medium

# Linux/Mac
./scripts/create_problem.sh <number> <name> <difficulty>
```

This will create:
```
problems/<difficulty>/<number>_<name>/
├── README.md
├── solution.cpp
└── test.cpp
```

### Step 2: Link to Topics

After creating a problem, link it to relevant topic directories:

```bash
# Windows
scripts\link_to_topics.bat problems\<difficulty>\<number>_<name> <topic1> [topic2] [topic3]

# Example
scripts\link_to_topics.bat problems\easy\001_two_sum arrays hash-table
```

**Common Topics:**
- `arrays`, `strings`, `linked_lists`, `trees`, `graphs`
- `dynamic_programming`, `backtracking`, `greedy`
- `sliding_window`, `two_pointers`, `binary_search`
- `hash-table`, `stack`, `queue`, `heap`
- `sorting`, `bit-manipulation`, `math`, `recursion`

**What This Does:**
- Creates junction points (symbolic links) in topic directories
- Allows accessing the same problem from multiple locations
- No file duplication - changes in one location reflect everywhere
- Example: `001_two_sum` appears in:
  - `problems/easy/001_two_sum/` (original)
  - `topics/arrays/001_two_sum/` (linked)
  - `topics/hash-table/001_two_sum/` (linked)

### Method 2: Manual Creation

1. **Create directory structure:**
   ```bash
   mkdir -p problems/easy/001_two_sum
   ```

2. **Create README.md** (see template below)

3. **Create solution.cpp** (see template below)

4. **Create test.cpp** (see template below)

---

## File Structure

### README.md Template

```markdown
# [Number]. Problem Name

**Difficulty:** Easy/Medium/Hard  
**Topics:** Topic1, Topic2, Topic3  
**Link:** [LeetCode](https://leetcode.com/problems/problem-name/)

## Problem Description

[Paste the problem description from LeetCode]

### Example 1:
\`\`\`
Input: [input]
Output: [output]
Explanation: [explanation]
\`\`\`

### Constraints:
- [constraint 1]
- [constraint 2]

## Approach

### Solution 1: [Approach Name]
[Explain the approach]

**Why this works:**
- [Reason 1]
- [Reason 2]

## Complexity Analysis

- **Time Complexity:** O(?)
  - [Explanation]

- **Space Complexity:** O(?)
  - [Explanation]

## Key Insights

1. [Insight 1]
2. [Insight 2]
3. [Insight 3]

## Related Problems

- [Problem 1] (Difficulty)
- [Problem 2] (Difficulty)

## Tags

`#tag1` `#tag2` `#difficulty`
```

### solution.cpp Template

```cpp
#include <vector>
#include <unordered_map>
// Add other necessary headers

using namespace std;

class Solution {
public:
    /**
     * [Problem Name] - [Approach Name]
     * 
     * Approach:
     * 1. [Step 1]
     * 2. [Step 2]
     * 3. [Step 3]
     * 
     * Time Complexity: O(?)
     * Space Complexity: O(?)
     */
    ReturnType functionName(Parameters) {
        // Implementation here
    }
};

/*
 * Alternative Solution: [Alternative Approach]
 * 
 * Time Complexity: O(?)
 * Space Complexity: O(?)
 */
class SolutionAlternative {
public:
    ReturnType functionName(Parameters) {
        // Alternative implementation
    }
};
```

### test.cpp Template

```cpp
#include <iostream>
#include <vector>
#include <cassert>
#include "solution.cpp"

using namespace std;

// Helper functions for testing
void printResult(/* parameters */) {
    // Print test results
}

void runTest(/* test parameters */, string testName) {
    Solution solution;
    cout << "\n" << testName << endl;
    
    // Run test
    auto result = solution.functionName(/* params */);
    
    // Verify result
    cout << "✓ PASSED" << endl;
}

int main() {
    cout << "========================================" << endl;
    cout << "Testing [Problem Name]" << endl;
    cout << "========================================" << endl;
    
    // Test Case 1
    runTest(/* params */, "Test 1: Description");
    
    // Test Case 2
    runTest(/* params */, "Test 2: Description");
    
    // Add more test cases
    
    cout << "\n========================================" << endl;
    cout << "All tests completed!" << endl;
    cout << "========================================" << endl;
    
    return 0;
}
```

---

## Coding Standards

### 1. Naming Conventions

```cpp
// Classes: PascalCase
class Solution { };

// Functions: camelCase
int twoSum() { }

// Variables: camelCase
int targetSum = 0;

// Constants: UPPER_SNAKE_CASE
const int MAX_SIZE = 100;
```

### 2. Code Organization

```cpp
class Solution {
public:
    // Public methods first
    vector<int> mainFunction() {
        // Implementation
    }

private:
    // Private helper methods
    void helperFunction() {
        // Implementation
    }
    
    // Private member variables
    int memberVariable;
};
```

### 3. Comments

```cpp
/**
 * Function-level documentation
 * Explain what the function does, approach, and complexity
 */
int function() {
    // Inline comments for complex logic
    int result = 0;
    
    // Explain non-obvious operations
    result = complexOperation();
    
    return result;
}
```

### 4. Code Style

```cpp
// Use spaces around operators
int sum = a + b;

// Use braces even for single-line if statements
if (condition) {
    doSomething();
}

// Prefer early returns
if (edge_case) {
    return result;
}

// Use meaningful variable names
int targetIndex = 0;  // Good
int ti = 0;           // Avoid
```

---

## Documentation Standards

### 1. Problem README

**Must include:**
- Problem number and name
- Difficulty level
- Topics/tags
- Link to LeetCode
- Problem description
- Examples with explanations
- Constraints
- Approach explanation
- Complexity analysis
- Key insights

**Optional but recommended:**
- Multiple approaches
- Related problems
- Common pitfalls
- Interview tips

### 2. Code Comments

**Function-level:**
```cpp
/**
 * Two Sum - Hash Map Solution
 * 
 * Approach:
 * 1. Use hash map to store numbers and indices
 * 2. For each number, check if complement exists
 * 3. Return indices when found
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
```

**Inline comments:**
```cpp
// Calculate complement we're looking for
int complement = target - nums[i];

// Check if complement exists in our map
if (map.find(complement) != map.end()) {
    return {map[complement], i};
}
```

---

## Testing Guidelines

### 1. Test Coverage

**Always test:**
- ✅ Basic cases (examples from problem)
- ✅ Edge cases (empty, single element)
- ✅ Boundary values (min, max)
- ✅ Negative numbers (if applicable)
- ✅ Large inputs (performance)
- ✅ Duplicate values (if applicable)

### 2. Test Structure

```cpp
void runTest(/* params */, string testName) {
    Solution solution;
    
    // 1. Print test name
    cout << "\n" << testName << endl;
    
    // 2. Print input
    cout << "Input: ";
    printInput(/* params */);
    
    // 3. Run solution
    auto result = solution.function(/* params */);
    
    // 4. Print output
    cout << "Output: ";
    printOutput(result);
    
    // 5. Verify correctness
    if (isCorrect(result, expected)) {
        cout << "✓ PASSED" << endl;
    } else {
        cout << "✗ FAILED" << endl;
    }
}
```

### 3. Test Cases to Include

```cpp
// Test 1: Basic example
runTest({2, 7, 11, 15}, 9, "Test 1: Basic case");

// Test 2: Edge case - minimum size
runTest({1, 2}, 3, "Test 2: Minimum size");

// Test 3: Edge case - duplicates
runTest({3, 3}, 6, "Test 3: Duplicates");

// Test 4: Negative numbers
runTest({-1, -2, -3}, -5, "Test 4: Negative numbers");

// Test 5: Large numbers
runTest({1000000, 2000000}, 3000000, "Test 5: Large numbers");

// Test 6: No solution (if applicable)
// runTest({1, 2, 3}, 10, "Test 6: No solution");
```

---

## Workflow

### 1. Before Starting
- [ ] Read the problem carefully
- [ ] Understand constraints
- [ ] Think about edge cases
- [ ] Consider multiple approaches

### 2. While Solving
- [ ] Start with brute force
- [ ] Optimize step by step
- [ ] Add comments as you code
- [ ] Test frequently

### 3. After Solving
- [ ] Write comprehensive tests
- [ ] Document your approach
- [ ] Analyze complexity
- [ ] Consider alternative solutions
- [ ] Update progress tracker

### 4. Commit Changes
```bash
git add .
git commit -m "Add solution for problem X: Problem Name"
git push
```

---

## Updating Progress

### 1. Update README.md

Update the progress tracker:
```markdown
| Difficulty | Solved | Total | Percentage |
|------------|--------|-------|------------|
| 🟢 Easy    | 1      | ~600  | 0.17%      |
```

### 2. Add to Recent Solutions

```markdown
### Recent Solutions
- [001. Two Sum](problems/easy/001_two_sum/) - Easy - Array, Hash Table
```

### 3. Update Topic Progress

```markdown
| Topic | Count | Progress |
|-------|-------|----------|
| Arrays | 1 | ██░░░░░░░░ 10% |
```

---

## Quality Checklist

Before marking a problem as complete:

- [ ] Solution compiles without errors
- [ ] All test cases pass
- [ ] Code is well-commented
- [ ] README is complete
- [ ] Complexity analysis is accurate
- [ ] Code follows style guidelines
- [ ] Alternative solutions considered
- [ ] Progress tracker updated

---

## Tips for Success

1. **Consistency** - Solve problems regularly
2. **Documentation** - Write clear explanations
3. **Testing** - Test thoroughly
4. **Review** - Revisit problems after a week
5. **Patterns** - Identify common patterns
6. **Time yourself** - Practice under time constraints

---

**Happy Problem Solving! 🎯**
