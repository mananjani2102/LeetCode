// LeetCode 2942 - Find Words Containing Character
// Approach: Linear Search with find()
// Time: O(n*m) | Space: O(1) extra

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;

        for (int i = 0; i < (int)words.size(); i++) {
            if (words[i].find(x) != string::npos) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<string> w1 = {"leet", "code"};
    vector<int> r1 = sol.findWordsContaining(w1, 'e');
    for (int x : r1) cout << x << " ";
    cout << endl; // 0 1

    vector<string> w2 = {"abc", "bcd", "aaaa", "cbc"};
    vector<int> r2 = sol.findWordsContaining(w2, 'a');
    for (int x : r2) cout << x << " ";
    cout << endl; // 0 2

    vector<string> w3 = {"abc", "bcd", "aaaa", "cbc"};
    vector<int> r3 = sol.findWordsContaining(w3, 'z');
    cout << "Size: " << r3.size() << endl; // 0

    return 0;
}
