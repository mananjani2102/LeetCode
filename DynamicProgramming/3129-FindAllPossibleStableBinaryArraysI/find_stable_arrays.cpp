// LeetCode 3129 - Find All Possible Stable Binary Arrays I
// Approach: 3D Dynamic Programming
// Time: O(zero * one * limit) | Space: O(zero * one)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        const int MOD = 1000000007;

        vector<vector<vector<long long>>> dp(
            zero + 1,
            vector<vector<long long>>(one + 1, vector<long long>(2, 0))
        );

        for (int i = 1; i <= limit && i <= zero; i++) dp[i][0][0] = 1;
        for (int i = 1; i <= limit && i <= one;  i++) dp[0][i][1] = 1;

        for (int z = 0; z <= zero; z++) {
            for (int o = 0; o <= one; o++) {

                for (int k = 1; k <= limit && z + k <= zero; k++)
                    dp[z + k][o][0] = (dp[z + k][o][0] + dp[z][o][1]) % MOD;

                for (int k = 1; k <= limit && o + k <= one; k++)
                    dp[z][o + k][1] = (dp[z][o + k][1] + dp[z][o][0]) % MOD;
            }
        }

        return (dp[zero][one][0] + dp[zero][one][1]) % MOD;
    }
};

int main() {
    Solution sol;

    cout << sol.numberOfStableArrays(1, 1, 2) << endl;  // 2
    cout << sol.numberOfStableArrays(1, 2, 1) << endl;  // 1
    cout << sol.numberOfStableArrays(3, 3, 2) << endl;  // 14

    return 0;
}