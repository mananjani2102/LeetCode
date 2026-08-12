// LeetCode 318 - Maximum Product of Word Lengths
// Approach: Bitmask + Pairwise Comparison
// Time: O(n^2 + total_chars) | Space: O(n)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> masks(n, 0);

        for (int i = 0; i < n; i++) {
            for (char ch : words[i]) {
                masks[i] |= (1 << (ch - 'a'));
            }
        }

        int maxProd = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if ((masks[i] & masks[j]) == 0) {
                    int product = (int)words[i].size() * (int)words[j].size();
                    maxProd = max(maxProd, product);
                }
            }
        }

        return maxProd;
    }
};

int main() {
    Solution sol;

    vector<string> words1 = {"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
    cout << sol.maxProduct(words1) << endl; // 16

    vector<string> words2 = {"a", "ab", "abc", "d", "cd", "bcd", "abcd"};
    cout << sol.maxProduct(words2) << endl; // 4

    vector<string> words3 = {"a", "aa", "aaa", "aaaa"};
    cout << sol.maxProduct(words3) << endl; // 0

    return 0;
}
