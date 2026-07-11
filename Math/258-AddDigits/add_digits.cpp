// LeetCode 258 - Add Digits
// Approach: Digital Root Formula (O(1))
// Time: O(1) | Space: O(1)

#include <iostream>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
        if (num == 0) return 0;
        if (num % 9 == 0) return 9;
        return num % 9;
    }
};

int main() {
    Solution sol;

    cout << sol.addDigits(38) << endl; // 2
    cout << sol.addDigits(0) << endl;  // 0

    return 0;
}
