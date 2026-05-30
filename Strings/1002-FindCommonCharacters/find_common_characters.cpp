// LeetCode 1002 - Find Common Characters
// Approach: Frequency Array + Min Comparison
// Time: O(n*m) | Space: O(1)

#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> common(26, INT_MAX);

        for (string &word : words) {
            vector<int> freq(26, 0);

            for (char ch : word) {
                freq[ch - 'a']++;
            }

            for (int i = 0; i < 26; i++) {
                common[i] = min(common[i], freq[i]);
            }
        }

        vector<string> result;

        for (int i = 0; i < 26; i++) {
            while (common[i] > 0) {
                result.push_back(string(1, 'a' + i));
                common[i]--;
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    vector<string> w1 = {"bella", "label", "roller"};
    vector<string> r1 = sol.commonChars(w1);
    for (string s : r1) cout << s << " ";
    cout << endl; // e l l

    vector<string> w2 = {"cool", "lock", "cook"};
    vector<string> r2 = sol.commonChars(w2);
    for (string s : r2) cout << s << " ";
    cout << endl; // c o

    return 0;
}
