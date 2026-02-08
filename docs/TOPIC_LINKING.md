# Topic Linking System

This document explains how the topic linking system works in this LeetCode journal.

## Overview

The topic linking system allows you to organize problems in two ways simultaneously:
1. **By Difficulty** - `problems/easy/`, `problems/medium/`, `problems/hard/`
2. **By Topic** - `topics/arrays/`, `topics/strings/`, etc.

This is achieved using **junction points** (Windows) or **symbolic links** (Linux/Mac), which create references to the same files without duplicating them.

## How It Works

### Single Source of Truth

Each problem is stored in **one location**:
```
problems/<difficulty>/<number>_<name>/
├── README.md
├── solution.cpp
└── test.cpp
```

### Topic Links

Topic directories contain **links** to these problems:
```
topics/<topic>/<number>_<name>/  → points to problems/<difficulty>/<number>_<name>/
```

### Example: Two Sum Problem

```
problems/easy/001_two_sum/          ← Original files here
├── README.md
├── solution.cpp
└── test.cpp

topics/arrays/001_two_sum/          ← Junction point (link)
topics/hash-table/001_two_sum/      ← Junction point (link)
```

When you edit files in `topics/arrays/001_two_sum/`, you're actually editing the files in `problems/easy/001_two_sum/`. Changes appear everywhere instantly!

## Benefits

### ✅ No File Duplication
- One problem = one set of files
- Changes sync automatically
- No risk of inconsistency

### ✅ Multiple Access Paths
- Browse by difficulty when tracking progress
- Browse by topic when studying specific patterns
- Same files, different organization

### ✅ Flexible Organization
- Link one problem to multiple topics
- Easy to reorganize without moving files
- Maintain clean directory structure

## Using the Linking System

### Creating Links

Use the `link_to_topics.bat` script:

```bash
# Windows
scripts\link_to_topics.bat <problem_path> <topic1> [topic2] [topic3] ...

# Example: Link Two Sum to arrays and hash-table topics
scripts\link_to_topics.bat problems\easy\001_two_sum arrays hash-table
```

### Multiple Topics

Link a problem to as many topics as relevant:

```bash
# Problem uses multiple techniques
scripts\link_to_topics.bat problems\medium\015_3sum arrays two_pointers sorting
```

### Workflow

1. **Create problem** using `create_problem.bat`
2. **Implement solution** in the problem directory
3. **Link to topics** using `link_to_topics.bat`
4. **Access from anywhere** - edit in either location

## Common Topics

### Data Structures
- `arrays` - Array manipulation
- `strings` - String processing
- `linked_lists` - Linked list operations
- `trees` - Binary trees, BST, etc.
- `graphs` - Graph algorithms
- `hash-table` - Hash maps/sets
- `stack` - Stack-based solutions
- `queue` - Queue-based solutions
- `heap` - Priority queues

### Algorithms
- `dynamic_programming` - DP problems
- `backtracking` - Backtracking solutions
- `greedy` - Greedy algorithms
- `sorting` - Sorting algorithms
- `binary_search` - Binary search
- `two_pointers` - Two pointer technique
- `sliding_window` - Sliding window
- `recursion` - Recursive solutions

### Other
- `bit-manipulation` - Bit operations
- `math` - Mathematical problems
- `design` - System design problems

## Technical Details

### Windows: Junction Points

Windows uses **junction points** created with `mklink /J`:

```cmd
mklink /J topics\arrays\001_two_sum problems\easy\001_two_sum
```

**Characteristics:**
- Works on NTFS file systems
- No special permissions required
- Transparent to applications
- Deleted links don't affect original files

### Linux/Mac: Symbolic Links

Linux/Mac use **symbolic links** created with `ln -s`:

```bash
ln -s ../../problems/easy/001_two_sum topics/arrays/001_two_sum
```

**Characteristics:**
- Works on all Unix file systems
- Relative paths recommended
- Transparent to applications
- Deleted links don't affect original files

## Best Practices

### 1. Always Edit in Original Location

While you *can* edit files through topic links, it's clearer to edit in the original location:

```
✅ Good: Edit problems/easy/001_two_sum/solution.cpp
⚠️  Works but confusing: Edit topics/arrays/001_two_sum/solution.cpp
```

### 2. Link After Implementation

Create links after you've implemented and tested the solution:

```bash
# 1. Create problem
scripts\create_problem.bat 1 two-sum easy

# 2. Implement solution
# Edit problems/easy/001_two_sum/solution.cpp

# 3. Test solution
# Run tests

# 4. Link to topics
scripts\link_to_topics.bat problems\easy\001_two_sum arrays hash-table
```

### 3. Choose Relevant Topics

Only link to topics that are **central** to the solution:

```bash
# ✅ Good: Core techniques used
scripts\link_to_topics.bat problems\easy\001_two_sum arrays hash-table

# ❌ Too many: Not all are central to the solution
scripts\link_to_topics.bat problems\easy\001_two_sum arrays hash-table sorting searching math
```

### 4. Update Topic READMEs

When linking to a topic, update that topic's README.md:

```markdown
# Array Problems

## Easy
- [001_two_sum](001_two_sum/) - Two Sum - Hash Map
- [026_remove_duplicates](026_remove_duplicates/) - Remove Duplicates - Two Pointers
```

## Troubleshooting

### Link Already Exists

```
[SKIP] Link already exists: topics\arrays\001_two_sum
```

**Solution:** The link is already created. No action needed.

### Permission Denied (Windows)

```
[ERROR] Failed to create link in: arrays
```

**Solution:** Run Command Prompt as Administrator for the first link creation.

### Broken Links

If you move or delete the original problem, links will break.

**Solution:** 
1. Delete broken links: `rmdir topics\arrays\001_two_sum`
2. Recreate problem in correct location
3. Re-create links

### Git and Links

**Windows Junction Points:**
- Git treats them as regular directories
- Files appear in both locations in Git
- Use `.gitignore` to exclude topic directories if desired

**Linux/Mac Symbolic Links:**
- Git stores them as links (small files)
- Original files only appear once in Git
- Recommended approach for version control

## Examples

### Example 1: Simple Problem

```bash
# Create problem
scripts\create_problem.bat 1 two-sum easy

# Implement solution
# ... edit files ...

# Link to topics
scripts\link_to_topics.bat problems\easy\001_two_sum arrays hash-table
```

### Example 2: Complex Problem

```bash
# Create problem
scripts\create_problem.bat 15 3sum medium

# Implement solution
# ... edit files ...

# Link to multiple topics
scripts\link_to_topics.bat problems\medium\015_3sum arrays two_pointers sorting
```

### Example 3: Updating Links

```bash
# Add new topic link
scripts\link_to_topics.bat problems\easy\001_two_sum recursion

# Result: Now linked to arrays, hash-table, AND recursion
```

## Summary

The topic linking system provides:
- ✅ Dual organization (difficulty + topic)
- ✅ No file duplication
- ✅ Automatic synchronization
- ✅ Flexible categorization
- ✅ Easy maintenance

Use `link_to_topics.bat` after creating each problem to maintain this organization!

---

**For more information:**
- [CONTRIBUTING.md](CONTRIBUTING.md) - How to add problems
- [QUICKSTART.md](../QUICKSTART.md) - Quick start guide
- [README.md](../README.md) - Main documentation
