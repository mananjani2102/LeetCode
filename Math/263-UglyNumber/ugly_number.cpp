// LeetCode 263 - Ugly Number
// Approach: Divide by 2, 3, 5 repeatedly
// Time: O(log n) | Space: O(1)

#include <iostream>
using namespace std;

class Solution {
public:
    bool isUgly(int n) {
        if (n <= 0) return false;

        while (n % 2 == 0) n /= 2;
        while (n % 3 == 0) n /= 3;
        while (n % 5 == 0) n /= 5;

        return n == 1;
    }
};

int main() {
    Solution sol;

    cout << sol.isUgly(6) << endl;  // 1 (true)
    cout << sol.isUgly(1) << endl;  // 1 (true)
    cout << sol.isUgly(14) << endl; // 0 (false)

    return 0;
}
