// LeetCode 3163 - String Compression III
// Approach: Chunking by Max 9 Repeats
// Time: O(n) | Space: O(n)

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int n = word.size();
        int i = 0;

        while (i < n) {
            char currentChar = word[i];
            int count = 0;

            while (i < n && word[i] == currentChar && count < 9) {
                i++;
                count++;
            }

            comp += to_string(count);
            comp += currentChar;
        }

        return comp;
    }
};

int main() {
    Solution sol;

    cout << sol.compressedString("abcde") << endl;             // 1a1b1c1d1e
    cout << sol.compressedString("aaaaaaaaaaaaaabb") << endl;  // 9a5a2b

    return 0;
}
