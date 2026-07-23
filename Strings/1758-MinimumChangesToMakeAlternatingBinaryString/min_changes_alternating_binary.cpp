// LeetCode 1758 - Minimum Changes To Make Alternating Binary String
// Approach: Count Mismatches with Two Patterns
// Time: O(n) | Space: O(1)

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int countStartWith0 = 0;

        for (int i = 0; i < (int)s.size(); i++) {
            char expected = (i % 2 == 0) ? '0' : '1';
            if (s[i] != expected) {
                countStartWith0++;
            }
        }

        int countStartWith1 = s.size() - countStartWith0;

        return min(countStartWith0, countStartWith1);
    }
};

int main() {
    Solution sol;

    cout << sol.minOperations("0100") << endl; // 1
    cout << sol.minOperations("10") << endl;   // 0
    cout << sol.minOperations("1111") << endl; // 2

    return 0;
}
