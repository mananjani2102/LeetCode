// LeetCode 1221 - Split a String in Balanced Strings
// Approach: Counter Balance
// Time: O(n) | Space: O(1)

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int balancedStringSplit(string s) {
        int balance = 0;
        int count = 0;

        for (char ch : s) {
            if (ch == 'R')
                balance++;
            else
                balance--;

            if (balance == 0)
                count++;
        }

        return count;
    }
};

int main() {
    Solution sol;

    cout << sol.balancedStringSplit("RLRRLLRLRL") << endl; // 4
    cout << sol.balancedStringSplit("RLRRRLLRLL") << endl; // 2
    cout << sol.balancedStringSplit("LLLLRRRR") << endl;   // 1

    return 0;
}
