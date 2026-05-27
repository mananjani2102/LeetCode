// LeetCode 438 - Find All Anagrams in a String
// Approach: Sliding Window + Frequency Array
// Time: O(n) | Space: O(1)

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;

        int n = s.size();
        int m = p.size();

        if (m > n) return ans;

        vector<int> pFreq(26, 0);
        vector<int> windowFreq(26, 0);

        for (char c : p) {
            pFreq[c - 'a']++;
        }

        for (int i = 0; i < m; i++) {
            windowFreq[s[i] - 'a']++;
        }

        if (windowFreq == pFreq) {
            ans.push_back(0);
        }

        for (int i = m; i < n; i++) {
            windowFreq[s[i] - 'a']++;
            windowFreq[s[i - m] - 'a']--;

            if (windowFreq == pFreq) {
                ans.push_back(i - m + 1);
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> r1 = sol.findAnagrams("cbaebabacd", "abc");
    for (int x : r1) cout << x << " ";
    cout << endl; // 0 6

    vector<int> r2 = sol.findAnagrams("abab", "ab");
    for (int x : r2) cout << x << " ";
    cout << endl; // 0 1 2

    return 0;
}
