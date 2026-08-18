// LeetCode 1827 - Minimum Operations to Make the Array Increasing
// Approach: Greedy
// Time: O(n) | Space: O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int operations = 0;

        for (int i = 1; i < (int)nums.size(); i++) {
            if (nums[i] <= nums[i - 1]) {
                int needed = nums[i - 1] + 1 - nums[i];
                operations += needed;
                nums[i] = nums[i - 1] + 1;
            }
        }

        return operations;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 1, 1};
    cout << sol.minOperations(nums1) << endl; // 3

    vector<int> nums2 = {1, 5, 2, 4, 1};
    cout << sol.minOperations(nums2) << endl; // 14

    vector<int> nums3 = {8};
    cout << sol.minOperations(nums3) << endl; // 0

    return 0;
}
