// LeetCode 14 - Longest Common Prefix
// Approach: Vertical Scanning
// Time: O(n*m) | Space: O(1)

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        for (int i = 0; i < (int)strs[0].size(); i++) {
            char current = strs[0][i];

            for (int j = 1; j < (int)strs.size(); j++) {
                if (i >= (int)strs[j].size() || strs[j][i] != current) {
                    return strs[0].substr(0, i);
                }
            }
        }

        return strs[0];
    }
};

int main() {
    Solution sol;

    vector<string> strs1 = {"flower", "flow", "flight"};
    cout << sol.longestCommonPrefix(strs1) << endl; // "fl"

    vector<string> strs2 = {"dog", "racecar", "car"};
    cout << sol.longestCommonPrefix(strs2) << endl; // ""

    return 0;
}