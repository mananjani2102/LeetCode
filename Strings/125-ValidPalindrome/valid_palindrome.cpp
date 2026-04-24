// LeetCode 125 - Valid Palindrome
// Approach: Two Pointers
// Time: O(n) | Space: O(1)

#include <iostream>
#include <cctype>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;
        while (left < right) {
            while (left < right && !isalnum(s[left])) left++;
            while (left < right && !isalnum(s[right])) right--;
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};

int main() {
    Solution sol;

    cout << sol.isPalindrome("A man, a plan, a canal: Panama") << endl; // 1 (true)
    cout << sol.isPalindrome("race a car") << endl;                     // 0 (false)
    cout << sol.isPalindrome(" ") << endl;                              // 1 (true)

    return 0;
}