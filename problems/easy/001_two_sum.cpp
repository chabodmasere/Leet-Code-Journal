/*
 * LeetCode Problem 1: Two Sum
 * Difficulty: Easy
 * Topics: Array, Hash Table
 * Link: https://leetcode.com/problems/two-sum/
 * 
 * Problem Description:
 * Given an array of integers nums and an integer target, return indices of the 
 * two numbers such that they add up to target.
 * You may assume that each input would have exactly one solution, and you may 
 * not use the same element twice.
 * You can return the answer in any order.
 * 
 * Example 1:
 * Input: nums = [2,7,11,15], target = 9
 * Output: [0,1]
 * Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
 * 
 * Example 2:
 * Input: nums = [3,2,4], target = 6
 * Output: [1,2]
 * 
 * Example 3:
 * Input: nums = [3,3], target = 6
 * Output: [0,1]
 */

#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * Two Sum - Hash Map Solution (Optimal)
     * 
     * Approach:
     * 1. Use a hash map to store numbers and their indices
     * 2. For each number, check if its complement (target - num) exists
     * 3. If found, return the indices
     * 4. Otherwise, add current number to hash map
     * 
     * Time Complexity: O(n) - single pass through array
     * Space Complexity: O(n) - hash map storage
     */
    vector<int> twoSum(vector<int>& nums, int target) {
        // Hash map to store: number -> index
        unordered_map<int, int> numMap;
        
        // Iterate through the array
        for (int i = 0; i < nums.size(); i++) {
            // Calculate the complement we're looking for
            int complement = target - nums[i];
            
            // Check if complement exists in our map
            if (numMap.find(complement) != numMap.end()) {
                // Found! Return the indices
                return {numMap[complement], i};
            }
            
            // Add current number and its index to map
            numMap[nums[i]] = i;
        }
        
        // No solution found (shouldn't happen per problem constraints)
        return {};
    }
};

// Test cases
int main() {
    Solution solution;
    
    // Test case 1
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> result1 = solution.twoSum(nums1, target1);
    cout << "Test 1: [" << result1[0] << ", " << result1[1] << "]" << endl;
    // Expected: [0, 1]
    
    // Test case 2
    vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    vector<int> result2 = solution.twoSum(nums2, target2);
    cout << "Test 2: [" << result2[0] << ", " << result2[1] << "]" << endl;
    // Expected: [1, 2]
    
    // Test case 3
    vector<int> nums3 = {3, 3};
    int target3 = 6;
    vector<int> result3 = solution.twoSum(nums3, target3);
    cout << "Test 3: [" << result3[0] << ", " << result3[1] << "]" << endl;
    // Expected: [0, 1]
    
    return 0;
}
