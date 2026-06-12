// LeetCode 2645 - Minimum Additions to Make Valid String
// Approach: Greedy Block Counting
// Time: O(n) | Space: O(1)

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int addMinimum(string word) {
        int blocks = 1;

        for (int i = 1; i < (int)word.length(); i++) {
            if (word[i] <= word[i - 1]) {
                blocks++;
            }
        }

        return blocks * 3 - word.length();
    }
};

int main() {
    Solution sol;

    cout << sol.addMinimum("b") << endl;   // 2
    cout << sol.addMinimum("aaa") << endl; // 6
    cout << sol.addMinimum("abc") << endl; // 0

    return 0;
}
