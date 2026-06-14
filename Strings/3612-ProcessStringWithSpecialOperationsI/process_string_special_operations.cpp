// LeetCode 3612 - Process String with Special Operations I
// Approach: Simulation
// Time: O(2^k * n) worst case due to doubling | Space: O(n)

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string processStr(string s) {
        string result;

        for (char ch : s) {
            if (ch >= 'a' && ch <= 'z') {
                result += ch;
            }
            else if (ch == '*') {
                if (!result.empty()) {
                    result.pop_back();
                }
            }
            else if (ch == '#') {
                result += result;
            }
            else if (ch == '%') {
                reverse(result.begin(), result.end());
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    cout << sol.processStr("a#b%*") << endl; // ba
    cout << sol.processStr("z*#") << endl;   // (empty)

    return 0;
}
