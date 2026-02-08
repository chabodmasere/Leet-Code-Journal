# Renaming Task: 3-digit to 4-digit Zero-Padding

## Progress Tracker

### Step 1: Update Scripts
- [x] Update `scripts/create_problem.bat` to use 4-digit padding

### Step 2: Rename Problem Files
- [x] Rename `problems/easy/001_two_sum.cpp` → `problems/easy/0001_two_sum.cpp`
- [x] Rename `problems/medium/167_two_sum_ii.cpp` → `problems/medium/0167_two_sum_ii.cpp`

### Step 3: Remove Old Topic Links
- [x] Delete `topics/arrays/001_two_sum.cpp` (junction point)
- [x] Delete `topics/hash-table/001_two_sum.cpp` (junction point)

### Step 4: Recreate Topic Links
- [x] Create `topics/arrays/0001_two_sum.cpp` → `problems/easy/0001_two_sum.cpp`
- [x] Create `topics/hash-table/0001_two_sum.cpp` → `problems/easy/0001_two_sum.cpp`

### Step 5: Update Documentation
- [x] Update README.md with new file paths

### Step 6: Verification
- [x] Verify all files renamed correctly
- [x] Verify topic links work
- [x] Test create_problem.bat script

## ✅ Task Complete!

All problem files have been successfully renamed from 3-digit to 4-digit zero-padding:
- `001_two_sum.cpp` → `0001_two_sum.cpp`
- `167_two_sum_ii.cpp` → `0167_two_sum_ii.cpp`

The create_problem.bat script now generates files with 4-digit padding (e.g., `0003_...`).
Topic junction points have been recreated with the new naming convention.
README.md has been updated with all new file paths.
