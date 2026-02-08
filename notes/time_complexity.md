# Time Complexity Cheat Sheet

A quick reference guide for Big O notation and complexity analysis.

## Common Time Complexities (Best to Worst)

| Complexity | Name | Example Operations |
|------------|------|-------------------|
| O(1) | Constant | Array access, hash table lookup |
| O(log n) | Logarithmic | Binary search, balanced tree operations |
| O(n) | Linear | Array traversal, linear search |
| O(n log n) | Linearithmic | Merge sort, heap sort, quick sort (average) |
| O(n²) | Quadratic | Nested loops, bubble sort |
| O(n³) | Cubic | Triple nested loops |
| O(2^n) | Exponential | Recursive fibonacci, subsets |
| O(n!) | Factorial | Permutations, traveling salesman |

## Visual Comparison

```
Operations for n = 10:
O(1)      = 1
O(log n)  = 3
O(n)      = 10
O(n log n)= 30
O(n²)     = 100
O(2^n)    = 1,024
O(n!)     = 3,628,800

Operations for n = 100:
O(1)      = 1
O(log n)  = 7
O(n)      = 100
O(n log n)= 700
O(n²)     = 10,000
O(2^n)    = 1.27 × 10^30
O(n!)     = 9.33 × 10^157
```

## Common Data Structure Operations

### Array
| Operation | Time Complexity |
|-----------|----------------|
| Access | O(1) |
| Search | O(n) |
| Insert (end) | O(1) amortized |
| Insert (middle) | O(n) |
| Delete (end) | O(1) |
| Delete (middle) | O(n) |

### Linked List
| Operation | Time Complexity |
|-----------|----------------|
| Access | O(n) |
| Search | O(n) |
| Insert (head) | O(1) |
| Insert (tail) | O(1) with tail pointer |
| Delete (head) | O(1) |
| Delete (given node) | O(1) |

### Hash Table
| Operation | Average | Worst |
|-----------|---------|-------|
| Search | O(1) | O(n) |
| Insert | O(1) | O(n) |
| Delete | O(1) | O(n) |

### Binary Search Tree (Balanced)
| Operation | Average | Worst |
|-----------|---------|-------|
| Search | O(log n) | O(n) |
| Insert | O(log n) | O(n) |
| Delete | O(log n) | O(n) |

### Heap
| Operation | Time Complexity |
|-----------|----------------|
| Find Min/Max | O(1) |
| Insert | O(log n) |
| Delete Min/Max | O(log n) |
| Heapify | O(n) |

### Stack/Queue
| Operation | Time Complexity |
|-----------|----------------|
| Push/Enqueue | O(1) |
| Pop/Dequeue | O(1) |
| Peek | O(1) |

## Common Algorithm Complexities

### Sorting Algorithms
| Algorithm | Best | Average | Worst | Space |
|-----------|------|---------|-------|-------|
| Bubble Sort | O(n) | O(n²) | O(n²) | O(1) |
| Selection Sort | O(n²) | O(n²) | O(n²) | O(1) |
| Insertion Sort | O(n) | O(n²) | O(n²) | O(1) |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) | O(n) |
| Quick Sort | O(n log n) | O(n log n) | O(n²) | O(log n) |
| Heap Sort | O(n log n) | O(n log n) | O(n log n) | O(1) |
| Counting Sort | O(n + k) | O(n + k) | O(n + k) | O(k) |

### Search Algorithms
| Algorithm | Time Complexity | Space |
|-----------|----------------|-------|
| Linear Search | O(n) | O(1) |
| Binary Search | O(log n) | O(1) |
| DFS | O(V + E) | O(V) |
| BFS | O(V + E) | O(V) |

## Rules for Calculating Complexity

### 1. Drop Constants
```cpp
O(2n) → O(n)
O(n/2) → O(n)
O(100) → O(1)
```

### 2. Drop Non-Dominant Terms
```cpp
O(n² + n) → O(n²)
O(n + log n) → O(n)
O(n! + n³) → O(n!)
```

### 3. Different Inputs = Different Variables
```cpp
// Two different arrays
for (int i = 0; i < a.length; i++) { }
for (int j = 0; j < b.length; j++) { }
// Time: O(a + b), NOT O(n)
```

### 4. Nested Loops = Multiply
```cpp
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        // O(n²)
    }
}
```

### 5. Sequential Loops = Add
```cpp
for (int i = 0; i < n; i++) { }
for (int j = 0; j < m; j++) { }
// Time: O(n + m)
```

## Common Patterns

### Pattern 1: Single Loop
```cpp
for (int i = 0; i < n; i++) {
    // O(1) operations
}
// Time: O(n)
```

### Pattern 2: Nested Loops
```cpp
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        // O(1) operations
    }
}
// Time: O(n²)
```

### Pattern 3: Halving Input
```cpp
while (n > 1) {
    n = n / 2;
}
// Time: O(log n)
```

### Pattern 4: Recursive Calls
```cpp
void recursion(int n) {
    if (n <= 1) return;
    recursion(n - 1);
    recursion(n - 1);
}
// Time: O(2^n)
```

### Pattern 5: Divide and Conquer
```cpp
void mergeSort(int arr[], int n) {
    if (n <= 1) return;
    mergeSort(left_half);   // T(n/2)
    mergeSort(right_half);  // T(n/2)
    merge();                // O(n)
}
// Time: O(n log n)
```

## Space Complexity

### Common Space Complexities

| Complexity | Example |
|------------|---------|
| O(1) | Few variables |
| O(log n) | Recursive call stack (balanced tree) |
| O(n) | Array, hash table |
| O(n²) | 2D array |

### Recursive Space Complexity
```cpp
// Space: O(n) due to call stack
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

// Space: O(log n) due to call stack
int binarySearch(int arr[], int left, int right, int target) {
    if (left > right) return -1;
    int mid = (left + right) / 2;
    if (arr[mid] == target) return mid;
    if (arr[mid] > target) 
        return binarySearch(arr, left, mid - 1, target);
    return binarySearch(arr, mid + 1, right, target);
}
```

## Interview Tips

### 1. Always State Your Assumptions
- "Assuming the array is sorted..."
- "If we can use extra space..."

### 2. Analyze Both Time and Space
- Don't forget space complexity!
- Mention trade-offs

### 3. Consider Best, Average, and Worst Cases
- Quick sort: O(n log n) average, O(n²) worst

### 4. Optimize Step by Step
1. Start with brute force
2. Identify bottlenecks
3. Use appropriate data structures
4. Consider different algorithms

## Quick Reference

**Need O(1) lookup?** → Use Hash Table  
**Need sorted data?** → Use Binary Search Tree or Sorted Array  
**Need to find min/max quickly?** → Use Heap  
**Working with sorted array?** → Consider Binary Search  
**Need to process in order?** → Use Queue (BFS)  
**Need to backtrack?** → Use Stack (DFS)  
**Optimization problem?** → Consider DP or Greedy  

## Practice Problems by Complexity

### O(1) - Constant
- Array element access
- Hash table operations

### O(log n) - Logarithmic
- Binary Search (704)
- Search in Rotated Sorted Array (33)

### O(n) - Linear
- Two Sum (1)
- Maximum Subarray (53)
- Merge Two Sorted Lists (21)

### O(n log n) - Linearithmic
- Merge Intervals (56)
- Sort Colors (75)
- Kth Largest Element (215)

### O(n²) - Quadratic
- 3Sum (15)
- Longest Palindromic Substring (5)

### O(2^n) - Exponential
- Subsets (78)
- Permutations (46)

---

**Remember:** Big O describes the upper bound of growth rate, not the exact number of operations!
