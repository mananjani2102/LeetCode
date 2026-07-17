// LeetCode 231 - Power of Two
// Approach: Bit Manipulation (n & (n-1))
// Time: O(1) | Space: O(1)

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        return (n & (n - 1)) == 0;
    }
};

int main() {
    Solution sol;

    cout << sol.isPowerOfTwo(1) << endl;  // 1 (true)
    cout << sol.isPowerOfTwo(16) << endl; // 1 (true)
    cout << sol.isPowerOfTwo(3) << endl;  // 0 (false)

    return 0;
}
