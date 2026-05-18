// LeetCode 53 - Maximum Subarray
// Approach: Kadane's Algorithm
// Time: O(n) | Space: O(1)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int currSum = nums[0];

        for (int i = 1; i < (int)nums.size(); i++) {
            currSum = max(nums[i], currSum + nums[i]);
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << sol.maxSubArray(nums1) << endl; // 6

    vector<int> nums2 = {1};
    cout << sol.maxSubArray(nums2) << endl; // 1

    vector<int> nums3 = {5, 4, -1, 7, 8};
    cout << sol.maxSubArray(nums3) << endl; // 23

    return 0;
}