// LeetCode 338 - Counting Bits
// Approach: Dynamic Programming (i & (i-1))
// Time: O(n) | Space: O(1) extra (excluding output)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            ans[i] = ans[i & (i - 1)] + 1;
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> r1 = sol.countBits(2);
    for (int x : r1) cout << x << " ";
    cout << endl; // 0 1 1

    vector<int> r2 = sol.countBits(5);
    for (int x : r2) cout << x << " ";
    cout << endl; // 0 1 1 2 1 2

    return 0;
}
