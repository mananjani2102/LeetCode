// LeetCode 69 - Sqrt(x)
// Approach: Binary Search
// Time: O(log x) | Space: O(1)

#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;

        long long left = 1, right = x;
        long long ans = 0;

        while (left <= right) {
            long long mid = left + (right - left) / 2;

            if (mid * mid <= x) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return (int)ans;
    }
};

int main() {
    Solution sol;

    cout << sol.mySqrt(4) << endl; // 2
    cout << sol.mySqrt(8) << endl; // 2

    return 0;
}
