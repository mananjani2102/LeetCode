// LeetCode 5 - Longest Palindromic Substring
// Approach: Expand Around Center
// Time: O(n²) | Space: O(1)

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int start = 0, maxLen = 1;

        for (int i = 0; i < s.size(); i++) {
            int l = i, r = i;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                if (r - l + 1 > maxLen) {
                    start = l;
                    maxLen = r - l + 1;
                }
                l--;
                r++;
            }

            l = i, r = i + 1;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                if (r - l + 1 > maxLen) {
                    start = l;
                    maxLen = r - l + 1;
                }
                l--;
                r++;
            }
        }
        return s.substr(start, maxLen);
    }
};

int main() {
    Solution sol;

    cout << sol.longestPalindrome("babad") << endl; // "bab"
    cout << sol.longestPalindrome("cbbd")  << endl;  // "bb"

    return 0;
}