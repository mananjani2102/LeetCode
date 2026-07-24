// LeetCode 389 - Find the Difference
// Approach: XOR Trick
// Time: O(n) | Space: O(1)

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        char result = 0;

        for (char ch : s) {
            result ^= ch;
        }

        for (char ch : t) {
            result ^= ch;
        }

        return result;
    }
};

int main() {
    Solution sol;

    cout << sol.findTheDifference("abcd", "abcde") << endl; // e
    cout << sol.findTheDifference("", "y") << endl;          // y

    return 0;
}
