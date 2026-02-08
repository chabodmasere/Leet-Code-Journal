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
- [001. Two Sum](problems/easy/001_two_sum/) - Easy - Array, Hash Table

---

## 📁 Repository Structure

```
Leet_Code_Journal/
│
├── problems/                      # Solutions organized by difficulty
│   ├── easy/                     # Easy problems
│   ├── medium/                   # Medium problems
│   └── hard/                     # Hard problems
│
├── topics/                        # Solutions organized by topic
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

1. **Use the helper script** (recommended):
   ```bash
   # Windows
   scripts\create_problem.bat <problem_number> <problem_name> <difficulty>
   
   # Linux/Mac
   ./scripts/create_problem.sh <problem_number> <problem_name> <difficulty>
   ```

2. **Manual creation**:
   - Create a folder: `problems/<difficulty>/<number>_<name>/`
   - Add files: `solution.cpp`, `README.md`, `test.cpp`

### Running Tests

```bash
# Windows
scripts\run_tests.bat

# Linux/Mac
./scripts/run_tests.sh
```

### Compiling a Solution

```bash
# Using g++
g++ -std=c++17 -o solution problems/easy/001_two_sum/solution.cpp
./solution

# Using the test file
g++ -std=c++17 -o test problems/easy/001_two_sum/test.cpp
./test
```

---

## 📝 Problem Structure

Each problem is a single C++ file:

```
problems/<difficulty>/<number>_<name>.cpp
```

### File Template
Each file contains:
- Problem description and examples (in comments)
- Solution class with implementation
- Test cases in main() function

Example: `problems/easy/001_two_sum.cpp`

---

## 🎓 Study Resources

### Patterns & Techniques
- [Common Problem-Solving Patterns](notes/patterns.md)
- [Time Complexity Guide](notes/time_complexity.md)

### Documentation
- [Setup Guide](docs/SETUP.md) - Environment setup instructions
- [Contributing Guide](docs/CONTRIBUTING.md) - How to add new problems
- [Topic Linking System](docs/TOPIC_LINKING.md) - How the dual organization works
- [Quick Start](QUICKSTART.md) - Get started in 5 minutes

### Templates
- [Data Structures](templates/data_structures/)
  - ListNode
  - TreeNode
  - GraphNode

---

## 📈 Statistics

### Streak
- Current Streak: 0 days
- Longest Streak: 0 days
- Last Solved: N/A

### Time Investment
- Total Time: 0 hours
- Average per Problem: 0 minutes

### Success Rate
- First Attempt Success: 0%
- Problems Revisited: 0

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

## 🛠️ Setup

### Prerequisites
- C++ compiler (g++, clang++, or MSVC)
- C++17 or later
- Git

### Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/Leet_Code_Journal.git
   cd Leet_Code_Journal
   ```

2. Verify your C++ compiler:
   ```bash
   g++ --version
   ```

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

## 🤝 Contributing

This is a personal learning journal, but feel free to:
- Suggest improvements
- Report issues
- Share alternative solutions

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

## 📝 Notes

- Solutions are written in C++17
- Focus on clarity and efficiency
- Each solution includes detailed comments
- Test cases cover edge cases

---

## 🏆 Achievements

- [ ] First problem solved
- [ ] 10 problems solved
- [ ] 50 problems solved
- [ ] 100 problems solved
- [ ] First hard problem solved
- [ ] 7-day streak
- [ ] 30-day streak
- [ ] All easy array problems completed
- [ ] All medium tree problems completed

---

## 📅 Study Schedule

| Day | Focus Area | Target |
|-----|------------|--------|
| Monday | Arrays | 2-3 problems |
| Tuesday | Strings | 2-3 problems |
| Wednesday | Linked Lists | 2-3 problems |
| Thursday | Trees | 2-3 problems |
| Friday | Dynamic Programming | 1-2 problems |
| Saturday | Review & Practice | 3-4 problems |
| Sunday | Mock Interview | 2-3 problems |

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

## 📞 Contact

For questions or discussions about solutions:
- GitHub Issues: [Create an issue](https://github.com/yourusername/Leet_Code_Journal/issues)

---

**Happy Coding! 🚀**

*Last Updated: [Date]*
