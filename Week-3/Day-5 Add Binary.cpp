Day-5 Add Binary.cpp

/*
Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 

Constraints:

Each string consists only of '0' or '1' characters.
1 <= a.length, b.length <= 10^4
Each string is either "0" or doesn't contain any leading zero.

*//

// Time:  O(n)
// Space: O(1)

class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        size_t res_len = max(a.length(), b.length()) ;

        size_t carry = 0;
        for (int i = 0; i < res_len; ++i) {
            const size_t a_bit_i = i < a.length() ? a[a.length() - 1 - i] - '0' : 0;
            const size_t b_bit_i = i < b.length() ? b[b.length() - 1 - i] - '0' : 0;
            size_t sum = carry + a_bit_i + b_bit_i;
            carry = sum / 2;
            sum %= 2;
            res.push_back('0' + sum);
        }
        if (carry) {
            res.push_back('0' + carry);
        }
        reverse(res.begin(), res.end());

        return res;
    }
};
