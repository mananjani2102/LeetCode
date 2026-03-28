// LeetCode 693 - Binary Number with Alternating Bits
// Approach: Bit Manipulation
// Time: O(log n) | Space: O(1)

#include <iostream>
using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prev = n & 1;
        n = n >> 1;

        while (n > 0) {
            int cur = n & 1;
            if (cur == prev) return false;
            prev = cur;
            n = n >> 1;
        }

        return true;
    }
};

int main() {
    Solution sol;

    cout << boolalpha;
    cout << sol.hasAlternatingBits(5)  << endl;  // true  (101)
    cout << sol.hasAlternatingBits(7)  << endl;  // false (111)
    cout << sol.hasAlternatingBits(11) << endl;  // false (1011)
    cout << sol.hasAlternatingBits(10) << endl;  // true  (1010)

    return 0;
}