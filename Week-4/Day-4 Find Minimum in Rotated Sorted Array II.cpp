Day-4 Find Minimum in Rotated Sorted Array II.cpp

/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

The array may contain duplicates.

Example 1:

Input: [1,3,5]
Output: 1
Example 2:

Input: [2,2,2,0,1]
Output: 0
Note:

This is a follow up problem to Find Minimum in Rotated Sorted Array.
Would allow duplicates affect the run-time complexity? How and why?


*/

// Time:  O(logn)
// Space: O(1)

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        // Find min left s.t. nums[left] < nums[left'].
        while (left < right && nums[left] >= nums[right]) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == nums[left]) {
                ++left;
            } else if (nums[mid] < nums[left]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return nums[left];
    }
};