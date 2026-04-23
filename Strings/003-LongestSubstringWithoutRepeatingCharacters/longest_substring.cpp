// LeetCode 3 - Longest Substring Without Repeating Characters
// Approach: Sliding Window
// Time: O(n) | Space: O(n)

#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int left = 0, maxLen = 0;

        for (int right = 0; right < s.size(); right++) {
            while (st.find(s[right]) != st.end()) {
                st.erase(s[left]);
                left++;
            }
            st.insert(s[right]);
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};

int main() {
    Solution sol;

    cout << sol.lengthOfLongestSubstring("abcabcbb") << endl; // 3
    cout << sol.lengthOfLongestSubstring("bbbbb")    << endl; // 1
    cout << sol.lengthOfLongestSubstring("pwwkew")   << endl; // 3

    return 0;
}