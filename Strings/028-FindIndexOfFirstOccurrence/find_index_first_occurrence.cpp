// LeetCode 28 - Find the Index of the First Occurrence in a String
// Approach: Brute Force Substring Search
// Time: O(n*m) | Space: O(1)

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = (int)haystack.size();
        int m = (int)needle.size();

        for (int i = 0; i <= n - m; i++) {
            int j = 0;
            while (j < m && haystack[i + j] == needle[j]) {
                j++;
            }
            if (j == m) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;

    cout << sol.strStr("sadbutsad", "sad") << endl;   // 0
    cout << sol.strStr("leetcode", "leeto") << endl;  // -1

    return 0;
}