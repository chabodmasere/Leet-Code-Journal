# 🚀 LeetCode Journal

A comprehensive collection of LeetCode problem solutions, organized by difficulty and topic, with detailed explanations and test cases.

## 📊 Progress Tracker

| Difficulty | Solved | Total | Percentage |
|------------|--------|-------|------------|
| 🟢 Easy    | 1      | ~600  | 0.17%      |
| 🟡 Medium  | 0      | ~1300 | 0%         |
| 🔴 Hard    | 0      | ~600  | 0%         |
| **Total**  | **1**  | **~2500** | **0.04%** |

### Recent Solutions
- [001. Two Sum](problems/easy/0001_two_sum.cpp) - Easy - Array, Hash Table

---

## 📁 Repository Structure

```
Leet_Code_Journal/
│
├── problems/                      # Solutions organized by difficulty
│   ├── easy/                     # Easy problems (single .cpp files)
│   ├── medium/                   # Medium problems
│   └── hard/                     # Hard problems
│
├── topics/                        # Solutions organized by topic (linked files)
│   ├── arrays/
│   ├── strings/
│   ├── linked_lists/
│   ├── trees/
│   ├── graphs/
│   ├── dynamic_programming/
│   ├── backtracking/
│   ├── sliding_window/
│   ├── two_pointers/
│   └── binary_search/
│
├── templates/                     # Reusable code templates
│   └── data_structures/          # Common data structure definitions
│
├── notes/                         # Study notes and patterns
│
├── scripts/                       # Automation scripts
│
└── docs/                          # Documentation
```

---

## 🎯 Problem Categories

### By Topic

| Topic | Count | Progress |
|-------|-------|----------|
| Arrays | 1 | █░░░░░░░░░ 10% |
| Hash Table | 1 | █░░░░░░░░░ 10% |
| Strings | 0 | ░░░░░░░░░░ 0% |
| Linked Lists | 0 | ░░░░░░░░░░ 0% |
| Trees | 0 | ░░░░░░░░░░ 0% |
| Graphs | 0 | ░░░░░░░░░░ 0% |
| Dynamic Programming | 0 | ░░░░░░░░░░ 0% |
| Backtracking | 0 | ░░░░░░░░░░ 0% |
| Sliding Window | 0 | ░░░░░░░░░░ 0% |
| Two Pointers | 0 | ░░░░░░░░░░ 0% |
| Binary Search | 0 | ░░░░░░░░░░ 0% |

---

## 🚀 Quick Start

### Adding a New Problem

**Use the helper script** (recommended):
```bash
# Windows
scripts\create_problem.bat <problem_number> <problem_name> <difficulty>

# Example
scripts\create_problem.bat 2 add-two-numbers medium
```

This creates a single C++ file: `problems/medium/0002_add-two-numbers.cpp`

### Linking to Topics

```bash
# Windows
scripts\link_to_topics.bat problems\easy\0001_two_sum.cpp arrays hash-table

# This creates linked files in topics/arrays/ and topics/hash-table/
```

### Compiling a Solution

```bash
# Compile and run
g++ -std=c++17 problems/easy/0001_two_sum.cpp -o test
test
```

---

## 📝 Problem Structure

Each problem is a **single C++ file** containing:
- Problem description and examples (in comments)
- Solution class with implementation
- Test cases in main() function

**Example:** `problems/easy/0001_two_sum.cpp`

```cpp
/*
 * LeetCode Problem 1: Two Sum
 * Difficulty: Easy
 * Topics: Array, Hash Table
 * 
 * Problem Description:
 * Given an array of integers nums and an integer target,
 * return indices of the two numbers such that they add up to target.
 */

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Solution implementation
    }
};

int main() {
    // Test cases
    return 0;
}
```

---

## 🎓 Study Resources

### Patterns & Techniques
- [Common Problem-Solving Patterns](notes/patterns.md)
- [Time Complexity Guide](notes/time_complexity.md)

### Documentation
- [Setup Guide](docs/SETUP.md) - Environment setup instructions
- [Contributing Guide](docs/CONTRIBUTING.md) - How to add new problems
- [Topic Linking System](docs/TOPIC_LINKING.md) - How the dual organization works
- [Compiler Setup](COMPILER_SETUP.md) - Install C++ compiler
- [Quick Start](QUICKSTART.md) - Get started in 5 minutes

### Templates
- [Data Structures](templates/data_structures/)
  - ListNode
  - TreeNode

---

## 🛠️ Setup

### Prerequisites
- C++ compiler (g++, clang++, or MSVC)
- C++17 or later
- Git

### Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/chabodmasere/Leet-Code-Journal.git
   cd Leet-Code-Journal
   ```

2. Install C++ compiler (if needed):
   - See [COMPILER_SETUP.md](COMPILER_SETUP.md) for detailed instructions

3. Start solving problems!

---

## 📚 Learning Path

### Phase 1: Foundations (Weeks 1-4)
1. **Arrays & Strings**
   - Two pointers
   - Sliding window
   - Hash tables

2. **Basic Data Structures**
   - Linked lists
   - Stacks & queues
   - Hash maps

### Phase 2: Intermediate (Weeks 5-12)
1. **Trees & Graphs**
   - Binary trees
   - BST operations
   - DFS/BFS
   - Graph traversal

2. **Algorithms**
   - Binary search
   - Sorting algorithms
   - Recursion

### Phase 3: Advanced (Weeks 13-24)
1. **Dynamic Programming**
   - 1D DP
   - 2D DP
   - Memoization

2. **Advanced Topics**
   - Backtracking
   - Greedy algorithms
   - Advanced graph algorithms

---

## 🎯 Goals

### Short-term (1 Month)
- [ ] Solve 30 easy problems
- [ ] Solve 15 medium problems
- [ ] Master array and string problems
- [ ] Complete sliding window pattern

### Medium-term (3 Months)
- [ ] Solve 100 easy problems
- [ ] Solve 50 medium problems
- [ ] Solve 10 hard problems
- [ ] Master all basic patterns

### Long-term (6 Months)
- [ ] Solve 200+ problems total
- [ ] Complete all major topics
- [ ] Achieve 50% medium problem success rate
- [ ] Ready for technical interviews

---

## 📖 Resources

### LeetCode
- [LeetCode Website](https://leetcode.com/)
- [LeetCode Discuss](https://leetcode.com/discuss/)
- [LeetCode Patterns](https://seanprashad.com/leetcode-patterns/)

### Learning Materials
- [NeetCode](https://neetcode.io/)
- [Tech Interview Handbook](https://www.techinterviewhandbook.org/)
- [Blind 75](https://www.teamblind.com/post/New-Year-Gift---Curated-List-of-Top-75-LeetCode-Questions-to-Save-Your-Time-OaM1orEU)

---

## 💡 Tips

1. **Understand before coding** - Spend time understanding the problem
2. **Start simple** - Begin with brute force, then optimize
3. **Test thoroughly** - Include edge cases
4. **Review regularly** - Revisit problems after a week
5. **Learn patterns** - Recognize common problem patterns
6. **Time yourself** - Practice under time constraints
7. **Explain your solution** - Practice explaining to others

---

## 📝 Notes

- Solutions are written in C++17
- Each problem is a single .cpp file
- Focus on clarity and efficiency
- Test cases included in each file
- Topic linking system for dual organization

---

## 🏆 Achievements

- [x] Repository organized
- [x] First problem solved (Two Sum)
- [ ] 10 problems solved
- [ ] 50 problems solved
- [ ] 100 problems solved
- [ ] First hard problem solved
- [ ] 7-day streak
- [ ] 30-day streak

---

## Disclaimer

Solutions are provided for educational purposes. If you are preparing for interviews, I strongly recommend attempting problems independently before referencing this repository.

---

**Happy Coding! 🚀**

*Last Updated: January 2026*
