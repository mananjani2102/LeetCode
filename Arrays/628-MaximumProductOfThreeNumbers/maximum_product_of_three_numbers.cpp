// LeetCode 628 - Maximum Product of Three Numbers
// Approach: Sort + Compare Two Cases
// Time: O(n log n) | Space: O(1)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int product1 = nums[n - 1] * nums[n - 2] * nums[n - 3];
        int product2 = nums[0] * nums[1] * nums[n - 1];

        return max(product1, product2);
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 2, 3};
    cout << sol.maximumProduct(nums1) << endl; // 6

    vector<int> nums2 = {1, 2, 3, 4};
    cout << sol.maximumProduct(nums2) << endl; // 24

    vector<int> nums3 = {-1, -2, -3};
    cout << sol.maximumProduct(nums3) << endl; // -6

    return 0;
}
