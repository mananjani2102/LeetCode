// LeetCode 9 - Palindrome Number
// Approach: Reverse the number
// Time Complexity: O(log n)
// Space Complexity: O(1)

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        long long revers = 0;
        int original = x;
        while (x != 0) {
            int digit = x % 10;
            revers = revers * 10 + digit;
            x = x / 10;
        }
        return original == revers;
    }
};

int main() {
    Solution sol;

    cout << sol.isPalindrome(121)  << endl;
    cout << sol.isPalindrome(-121) << endl; 
    cout << sol.isPalindrome(10)   << endl; 

    return 0;
}