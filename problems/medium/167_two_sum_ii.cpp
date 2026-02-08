/*
Problem: Two Sum II - Input Array is Sorted

Description:
Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, 
find two numbers such that they add up to a specific target number. Let these two numbers be 
numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

Return the indices of the two numbers, index1 and index2, added by one as an integer array 
[index1, index2] of length 2.

The tests are generated such that there is exactly one solution. You may not use the same 
element twice.

Your solution must use only constant extra space.

--------------------------------------------------

Examples:

Example 1:
Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].

Example 2:
Input: numbers = [2,3,4], target = 6
Output: [1,3]
Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].

Example 3:
Input: numbers = [-1,0], target = -1
Output: [1,2]
Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We return [1, 2].

--------------------------------------------------

Constraints:
- 2 <= numbers.length <= 3 * 10^4
- -1000 <= numbers[i] <= 1000
- numbers is sorted in non-decreasing order
- -1000 <= target <= 1000
- The tests are generated such that there is exactly one solution

--------------------------------------------------

Approach:
Since the array is sorted, we can use the two-pointer technique:
1. Initialize two pointers: left at the beginning (index 0) and right at the end (index n-1)
2. Calculate the sum of elements at both pointers
3. If sum equals target, return the indices (1-indexed)
4. If sum is less than target, move left pointer right to increase the sum
5. If sum is greater than target, move right pointer left to decrease the sum
6. Repeat until we find the solution

Time Complexity: O(n) - we traverse the array at most once
Space Complexity: O(1) - only using two pointers

--------------------------------------------------
*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            
            if (sum == target) {
                // Return 1-indexed positions
                return {left + 1, right + 1};
            } else if (sum < target) {
                // Need a larger sum, move left pointer right
                left++;
            } else {
                // Need a smaller sum, move right pointer left
                right--;
            }
        }
        
        // Should never reach here based on problem constraints
        return {-1, -1};
    }
};
