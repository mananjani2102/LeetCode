// LeetCode 945 - Minimum Increment to Make Array Unique
// Approach: Sort + Greedy Increment
// Time: O(n log n) | Space: O(1)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int moves = 0;

        for (int i = 1; i < (int)nums.size(); i++) {
            if (nums[i] <= nums[i - 1]) {
                int needed = nums[i - 1] + 1 - nums[i];
                moves += needed;
                nums[i] = nums[i - 1] + 1;
            }
        }

        return moves;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 2, 2};
    cout << sol.minIncrementForUnique(nums1) << endl; // 1

    vector<int> nums2 = {3, 2, 1, 2, 1, 7};
    cout << sol.minIncrementForUnique(nums2) << endl; // 6

    return 0;
}
