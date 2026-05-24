// LeetCode 387 - First Unique Character in a String
// Approach: Frequency Array
// Time: O(n) | Space: O(1)

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        for (int i = 0; i < (int)s.size(); i++) {
            if (freq[s[i] - 'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;

    cout << sol.firstUniqChar("leetcode") << endl;
    cout << sol.firstUniqChar("loveleetcode") << endl;
    cout << sol.firstUniqChar("aabb") << endl;

    return 0;
}
