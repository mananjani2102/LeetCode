// LeetCode 3010 - Divide an Array Into Subarrays With Minimum Cost I
// Approach: Brute Force (Find 2 smallest elements after index 0)
// Time: O(n^2) | Space: O(1)

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n   = nums.size();
        int ans = INT_MAX;

        for (int i = 1; i < n; i++)
            for (int j = i + 1; j < n; j++)
                ans = min(ans, nums[0] + nums[i] + nums[j]);

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> n1 = {1, 2, 3, 12};
    cout << sol.minimumCost(n1) << endl;  // 6

    vector<int> n2 = {5, 4, 3};
    cout << sol.minimumCost(n2) << endl;  // 12

    vector<int> n3 = {10, 3, 1, 1};
    cout << sol.minimumCost(n3) << endl;  // 12

    return 0;
}