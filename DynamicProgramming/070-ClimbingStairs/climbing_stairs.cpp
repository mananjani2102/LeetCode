// LeetCode 70 - Climbing Stairs
// Approach: Dynamic Programming (Fibonacci Pattern)
// Time: O(n) | Space: O(1)

#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;

        int a = 1, b = 2;

        for (int i = 3; i <= n; i++) {
            int c = a + b;
            a = b;
            b = c;
        }

        return b;
    }
};

int main() {
    Solution sol;

    cout << sol.climbStairs(2) << endl; // 2
    cout << sol.climbStairs(3) << endl; // 3

    return 0;
}
