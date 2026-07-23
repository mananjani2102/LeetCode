// LeetCode 896 - Monotonic Array
// Approach: Single Pass with Two Flags
// Time: O(n) | Space: O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool increasing = true;
        bool decreasing = true;

        for (int i = 1; i < (int)nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                decreasing = false;
            }
            if (nums[i] < nums[i - 1]) {
                increasing = false;
            }
        }

        return increasing || decreasing;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 2, 2, 3};
    cout << sol.isMonotonic(nums1) << endl; // 1 (true)

    vector<int> nums2 = {6, 5, 4, 4};
    cout << sol.isMonotonic(nums2) << endl; // 1 (true)

    vector<int> nums3 = {1, 3, 2};
    cout << sol.isMonotonic(nums3) << endl; // 0 (false)

    return 0;
}
