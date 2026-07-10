// LeetCode 561 - Array Partition
// Approach: Sort + Pick Alternate Elements
// Time: O(n log n) | Space: O(1)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int sum = 0;
        for (int i = 0; i < (int)nums.size(); i += 2) {
            sum += nums[i];
        }

        return sum;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 4, 3, 2};
    cout << sol.arrayPairSum(nums1) << endl; // 4

    vector<int> nums2 = {6, 2, 6, 5, 1, 2};
    cout << sol.arrayPairSum(nums2) << endl; // 9

    return 0;
}
