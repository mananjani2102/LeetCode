// LeetCode 392 - Is Subsequence
// Approach: Two Pointers
// Time: O(n) | Space: O(1)

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;

        while (i < (int)s.size() && j < (int)t.size()) {
            if (s[i] == t[j]) {
                i++;
            }
            j++;
        }

        return i == (int)s.size();
    }
};

int main() {
    Solution sol;

    cout << sol.isSubsequence("abc", "ahbgdc") << endl; // 1 (true)
    cout << sol.isSubsequence("axc", "ahbgdc") << endl; // 0 (false)

    return 0;
}
