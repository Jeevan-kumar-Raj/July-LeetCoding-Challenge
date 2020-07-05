Day-4 Ugly Number II.cpp

/*

Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 

Example:

Input: n = 10
Output: 12
Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
Note:  

1 is typically treated as an ugly number.
n does not exceed 1690.

*/



// Time:  O(n)
// Space: O(n)

// DP solution. (12ms)
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> uglies(n);
        uglies[0] = 1;
    
        int f2 = 2, f3 = 3, f5 = 5;
        int idx2 = 0, idx3 = 0, idx5 = 0;
    
        for (int i = 1; i < n; ++i) {
            int min_val = min(min(f2, f3), f5);
            uglies[i] = min_val;
    
            if (min_val == f2) {
                f2 = 2 * uglies[++idx2];
            }
            if (min_val == f3) {
                f3 = 3 * uglies[++idx3];
            }
            if (min_val == f5) {
                f5 = 5 * uglies[++idx5];
            }
        }
    
        return uglies[n - 1];
    }
};