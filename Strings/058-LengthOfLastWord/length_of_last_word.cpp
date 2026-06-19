// LeetCode 58 - Length of Last Word
// Approach: Reverse Traversal
// Time: O(n) | Space: O(1)

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        int i = s.size() - 1;

        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }

        return length;
    }
};

int main() {
    Solution sol;

    cout << sol.lengthOfLastWord("Hello World") << endl;            // 5
    cout << sol.lengthOfLastWord("   fly me   to   the moon  ") << endl; // 4
    cout << sol.lengthOfLastWord("luffy is still joyboy") << endl;  // 6

    return 0;
}
