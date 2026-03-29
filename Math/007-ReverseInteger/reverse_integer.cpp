// LeetCode 7 - Reverse Integer
// Approach: Pop and Push Digits
// Time Complexity: O(log n)
// Space Complexity: O(1)

#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int result = 0;
        while (x != 0) {
            int digit = x % 10;
            x /= 10;
            if (result > INT_MAX / 10 || result < INT_MIN / 10) {
                return 0;
            }
            result = result * 10 + digit;
        }
        return result;
    }
};

int main() {
    Solution sol;

    cout << sol.reverse(123)  << endl;  // Output: 321
    cout << sol.reverse(-123) << endl;  // Output: -321
    cout << sol.reverse(120)  << endl;  // Output: 21

    return 0;
}