# LeetCode Journal

A C++17 journal for working through LeetCode problems: one file per problem, with the problem
statement, my approach and the solution together, plus reference notes on common patterns and
complexity analysis.

## Status

The journal is set up and at an early stage.

| Problem | Difficulty | Topics | State |
| --- | --- | --- | --- |
| [1. Two Sum](problems/easy/0001_two_sum.cpp) | Easy | Array, hash table | Problem written up, solution to do |
| [167. Two Sum II: Input Array Is Sorted](problems/medium/0167_two_sum_ii.cpp) | Medium | Array, two pointers | Approach and complexity written up, code to do |

**Solved: 0 easy, 0 medium, 0 hard.**

## How a problem file is laid out

Each problem is a single `.cpp` file named `<4-digit number>_<name>.cpp` under its difficulty:

```cpp
/*
Problem: Two Sum II - Input Array is Sorted

Description:   the problem statement
Examples:      inputs, outputs and explanations
Constraints:   the input limits
Approach:      the idea, step by step
Time Complexity / Space Complexity
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // solution
    }
};
```

Writing the approach and its complexity before the code is the point of the journal: it is the
part worth rereading later.

## Reference notes

- [Problem-solving patterns](notes/patterns.md): two pointers, sliding window, fast and slow pointers, hash maps, binary search, DFS, BFS, dynamic programming, backtracking and greedy, each with when to use it and a C++ template.
- [Time and space complexity](notes/time_complexity.md): common complexities, data structure and algorithm costs, and the rules for working them out.
- [Array problems](topics/arrays/README.md): the patterns that come up most in array questions.

`templates/data_structures/` has the standard `ListNode` and `TreeNode` definitions LeetCode
uses, ready to include when testing locally.

## Adding a problem

On Windows, the helper script creates the file with the right name in the right folder:

```bat
scripts\create_problem.bat 2 add-two-numbers medium
```

That creates `problems/medium/0002_add-two-numbers.cpp`. On macOS or Linux, create the file by
hand using the same naming.

To compile and run a solution locally, add a `main()` with test cases and the headers it needs:

```bash
g++ -std=c++17 problems/medium/0167_two_sum_ii.cpp -o solution
./solution
```

## Repository layout

```text
problems/
├── easy/                    one .cpp file per problem
└── medium/
notes/                       patterns and complexity reference
topics/arrays/               notes on array problems
templates/data_structures/   ListNode.h, TreeNode.h
scripts/                     Windows helper scripts
docs/                        setup, contributing and topic-linking guides
archive/                     earlier project kept for reference (see below)
```

`QUICKSTART.md` and the guides in `docs/` were written for an earlier layout that used a folder
per problem with separate solution and test files. Where they disagree with this README, this
README is current.

## Archive: a small C++ interpreter

Before it became a LeetCode journal, this repository held a C++ interpreter written from
scratch, which is kept in [`archive/`](archive/). It is about 2,000 lines of C++17:

| Stage | Files | Role |
| --- | --- | --- |
| Tokens | `compiler/token.*` | Token types and keyword table |
| Lexer | `compiler/lexer.*` | Source text to tokens, including comments and string literals |
| AST | `compiler/ast.*` | Expression and statement nodes, with a visitor interface |
| Parser | `compiler/parser.*` | Recursive descent with operator precedence and line/column errors |
| Interpreter | `compiler/interpreter.*` | Walks the AST, with a symbol table and recursive function calls |
| Driver | `main.cpp` | Command line with tokens-only, parse-only and run modes |

It comes with six example programs, a Makefile, a CMake build and test scripts. Its own
[test report](archive/TEST_REPORT.md) records that it had not been compiled or run when it was
archived, so treat it as unverified.

## Disclaimer

Solutions are for my own learning. If you are preparing for interviews, attempt each problem
yourself before reading anyone's solution, including these.

## License

[MIT](LICENSE)

## Author

**Chabod Masere**
