// LeetCode 405 - Convert a Number to Hexadecimal
// Approach: Bit Masking (4 bits at a time)
// Time: O(1) fixed 8 iterations max | Space: O(1)

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";

        string hexDigits = "0123456789abcdef";
        string result = "";

        unsigned int n = (unsigned int)num;

        while (n != 0) {
            int digit = n & 15;
            result += hexDigits[digit];
            n >>= 4;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    Solution sol;

    cout << sol.toHex(26) << endl; // 1a
    cout << sol.toHex(-1) << endl; // ffffffff

    return 0;
}
