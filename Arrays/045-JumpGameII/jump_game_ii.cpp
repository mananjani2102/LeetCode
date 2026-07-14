// LeetCode 45 - Jump Game II
// Approach: Greedy BFS-style (Level by Level)
// Time: O(n) | Space: O(1)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0;
        int currentEnd = 0;
        int farthest = 0;

        for (int i = 0; i < n - 1; i++) {
            farthest = max(farthest, i + nums[i]);

            if (i == currentEnd) {
                jumps++;
                currentEnd = farthest;
            }
        }

        return jumps;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {2, 3, 1, 1, 4};
    cout << sol.jump(nums1) << endl; // 2

    vector<int> nums2 = {2, 3, 0, 1, 4};
    cout << sol.jump(nums2) << endl; // 2

    return 0;
}
