Day-2 Pow(x, n).cpp

/*
Implement pow(x, n), which calculates x raised to the power n (xn).

Example 1:

Input: 2.00000, 10
Output: 1024.00000
Example 2:

Input: 2.10000, 3
Output: 9.26100
Example 3:

Input: 2.00000, -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
Note:

-100.0 < x < 100.0
n is a 32-bit signed integer, within the range [−231, 231 − 1]


*/

// Time:  O(logn) = O(1)
// Space: O(1)

// Iterative solution.
class Solution {
public:
    double myPow(double x, int n) {
        double result = 1;
        long long abs_n = abs(static_cast<long long>(n));
        while (abs_n > 0) {
            if (abs_n & 1) {
                result *= x;
            }
            abs_n >>= 1;
            x *= x;
        }
        return n < 0 ? 1 / result : result;
    }
};

