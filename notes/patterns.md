# Common LeetCode Problem-Solving Patterns

This guide covers the most common patterns you'll encounter in LeetCode problems.

## Table of Contents
1. [Two Pointers](#two-pointers)
2. [Sliding Window](#sliding-window)
3. [Fast & Slow Pointers](#fast--slow-pointers)
4. [Hash Map/Set](#hash-mapset)
5. [Binary Search](#binary-search)
6. [DFS (Depth-First Search)](#dfs-depth-first-search)
7. [BFS (Breadth-First Search)](#bfs-breadth-first-search)
8. [Dynamic Programming](#dynamic-programming)
9. [Backtracking](#backtracking)
10. [Greedy](#greedy)

---

## Two Pointers

**When to use:** Problems involving sorted arrays, palindromes, or finding pairs/triplets.

**Pattern:**
```cpp
int left = 0, right = n - 1;
while (left < right) {
    // Process elements at left and right
    if (condition) {
        left++;
    } else {
        right--;
    }
}
```

**Common Problems:**
- Two Sum (sorted array)
- Three Sum
- Container With Most Water
- Valid Palindrome
- Remove Duplicates from Sorted Array

**Time Complexity:** Usually O(n)

---

## Sliding Window

**When to use:** Problems involving subarrays/substrings with specific properties.

**Pattern:**
```cpp
int left = 0;
for (int right = 0; right < n; right++) {
    // Expand window by including arr[right]
    
    while (window_condition_broken) {
        // Shrink window from left
        left++;
    }
    
    // Update result
}
```

**Common Problems:**
- Maximum Sum Subarray of Size K
- Longest Substring Without Repeating Characters
- Minimum Window Substring
- Longest Repeating Character Replacement

**Time Complexity:** Usually O(n)

---

## Fast & Slow Pointers

**When to use:** Linked list problems, cycle detection.

**Pattern:**
```cpp
ListNode* slow = head;
ListNode* fast = head;

while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
    
    if (slow == fast) {
        // Cycle detected
    }
}
```

**Common Problems:**
- Linked List Cycle
- Find Middle of Linked List
- Happy Number
- Palindrome Linked List

**Time Complexity:** O(n)

---

## Hash Map/Set

**When to use:** Need O(1) lookup, counting frequencies, finding duplicates.

**Pattern:**
```cpp
unordered_map<int, int> map;
for (int num : nums) {
    if (map.find(num) != map.end()) {
        // Found duplicate or complement
    }
    map[num] = value;
}
```

**Common Problems:**
- Two Sum
- Group Anagrams
- Subarray Sum Equals K
- Longest Consecutive Sequence

**Time Complexity:** O(n) average

---

## Binary Search

**When to use:** Sorted arrays, finding boundaries, optimization problems.

**Pattern:**
```cpp
int left = 0, right = n - 1;
while (left <= right) {
    int mid = left + (right - left) / 2;
    
    if (arr[mid] == target) {
        return mid;
    } else if (arr[mid] < target) {
        left = mid + 1;
    } else {
        right = mid - 1;
    }
}
```

**Common Problems:**
- Binary Search
- Search in Rotated Sorted Array
- Find First and Last Position
- Koko Eating Bananas

**Time Complexity:** O(log n)

---

## DFS (Depth-First Search)

**When to use:** Tree/graph traversal, exploring all paths.

**Pattern (Recursive):**
```cpp
void dfs(TreeNode* node) {
    if (!node) return;
    
    // Process current node
    
    dfs(node->left);
    dfs(node->right);
}
```

**Pattern (Iterative):**
```cpp
stack<TreeNode*> st;
st.push(root);

while (!st.empty()) {
    TreeNode* node = st.top();
    st.pop();
    
    // Process node
    
    if (node->right) st.push(node->right);
    if (node->left) st.push(node->left);
}
```

**Common Problems:**
- Binary Tree Inorder Traversal
- Path Sum
- Number of Islands
- Clone Graph

**Time Complexity:** O(V + E) for graphs, O(n) for trees

---

## BFS (Breadth-First Search)

**When to use:** Shortest path, level-order traversal.

**Pattern:**
```cpp
queue<TreeNode*> q;
q.push(root);

while (!q.empty()) {
    int size = q.size();
    for (int i = 0; i < size; i++) {
        TreeNode* node = q.front();
        q.pop();
        
        // Process node
        
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
}
```

**Common Problems:**
- Binary Tree Level Order Traversal
- Minimum Depth of Binary Tree
- Rotting Oranges
- Word Ladder

**Time Complexity:** O(V + E) for graphs, O(n) for trees

---

## Dynamic Programming

**When to use:** Optimization problems, counting problems, overlapping subproblems.

**Pattern (Top-Down with Memoization):**
```cpp
unordered_map<int, int> memo;

int dp(int n) {
    if (base_case) return result;
    if (memo.find(n) != memo.end()) return memo[n];
    
    memo[n] = // recursive calls
    return memo[n];
}
```

**Pattern (Bottom-Up):**
```cpp
vector<int> dp(n + 1);
dp[0] = base_case;

for (int i = 1; i <= n; i++) {
    dp[i] = // compute from previous states
}
```

**Common Problems:**
- Fibonacci Number
- Climbing Stairs
- Coin Change
- Longest Increasing Subsequence
- House Robber

**Time Complexity:** Usually O(n) or O(n²)

---

## Backtracking

**When to use:** Finding all solutions, permutations, combinations.

**Pattern:**
```cpp
void backtrack(vector<int>& current, /* other params */) {
    if (is_solution(current)) {
        result.push_back(current);
        return;
    }
    
    for (int choice : choices) {
        // Make choice
        current.push_back(choice);
        
        // Recurse
        backtrack(current, /* params */);
        
        // Undo choice
        current.pop_back();
    }
}
```

**Common Problems:**
- Permutations
- Combinations
- Subsets
- N-Queens
- Sudoku Solver

**Time Complexity:** Usually exponential O(2^n) or O(n!)

---

## Greedy

**When to use:** Optimization problems where local optimal leads to global optimal.

**Pattern:**
```cpp
sort(arr.begin(), arr.end());

for (int i = 0; i < n; i++) {
    // Make greedy choice
    if (is_valid_choice(arr[i])) {
        // Take it
    }
}
```

**Common Problems:**
- Jump Game
- Gas Station
- Meeting Rooms II
- Task Scheduler

**Time Complexity:** Usually O(n log n) due to sorting

---

## How to Identify Patterns

| Problem Type | Pattern to Consider |
|--------------|-------------------|
| Sorted array | Binary Search, Two Pointers |
| Subarray/substring | Sliding Window |
| Linked list cycle | Fast & Slow Pointers |
| Need O(1) lookup | Hash Map/Set |
| Tree traversal | DFS/BFS |
| All combinations | Backtracking |
| Shortest path | BFS |
| Optimization with choices | DP or Greedy |
| Graph connectivity | DFS/BFS, Union Find |

---

## Practice Strategy

1. **Learn one pattern at a time**
2. **Solve 5-10 problems per pattern**
3. **Identify the pattern before coding**
4. **Practice variations of the same pattern**
5. **Review and revisit problems**

---

**Remember:** Most problems combine multiple patterns. Practice identifying which patterns apply!
