Day-2 Single Number III.cpp

/*
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

Example:

Input:  [1,2,1,3,2,5]
Output: [3,5]
Note:

The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?


*/

// Time:  O(n)
// Space: O(1)

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // Xor all the elements to get x ^ y.
        const auto x_xor_y = accumulate(nums.cbegin(), nums.cend(), 0, bit_xor<int>());

        // Get the last bit where 1 occurs by "x & ~(x - 1)"
        // Because -(x - 1) = ~(x - 1) + 1 <=> -x = ~(x - 1) 
        // So we can also get the last bit where 1 occurs by "x & -x"
        const auto bit = x_xor_y & -x_xor_y;

        // Get the subset of A where the number has the bit.
        // The subset only contains one of the two integers, call it x.
        // Xor all the elements in the subset to get x.
        vector<int> result(2, 0);
        for (const auto& i : nums) {
            result[static_cast<bool>(i & bit)] ^= i;
        }
        return result;
    }
};
