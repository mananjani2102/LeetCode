// LeetCode 1768 - Merge Strings Alternately
// Approach: Two Pointers
// Time: O(n+m) | Space: O(n+m)

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int i = 0, j = 0;
        while (i < (int)word1.size() && j < (int)word2.size()) {
            ans += word1[i++];
            ans += word2[j++];
        }
        while (i < (int)word1.size()) {
            ans += word1[i++];
        }
        while (j < (int)word2.size()) {
            ans += word2[j++];
        }
        return ans;
    }
};

int main() {
    Solution sol;

    cout << sol.mergeAlternately("abc", "pqr") << endl;   // apbqcr
    cout << sol.mergeAlternately("ab", "pqrs") << endl;   // apbqrs
    cout << sol.mergeAlternately("abcd", "pq") << endl;   // apbqcd

    return 0;
}
