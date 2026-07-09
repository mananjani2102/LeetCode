// LeetCode 459 - Repeated Substring Pattern
// Approach: String Concatenation Trick
// Time: O(n) | Space: O(n)

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string doubled = (s + s).substr(1, 2 * s.size() - 2);
        return doubled.find(s) != string::npos;
    }
};

int main() {
    Solution sol;

    cout << sol.repeatedSubstringPattern("abab") << endl;         // 1 (true)
    cout << sol.repeatedSubstringPattern("aba") << endl;           // 0 (false)
    cout << sol.repeatedSubstringPattern("abcabcabcabc") << endl;  // 1 (true)

    return 0;
}
