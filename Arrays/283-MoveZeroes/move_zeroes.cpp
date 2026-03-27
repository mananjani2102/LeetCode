// LeetCode 283 - Move Zeroes
// Approach: Two Pointers
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[j] = nums[i];
                j++;
            }
        }
        while (j < nums.size()) {
            nums[j] = 0;
            j++;
        }
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {0, 1, 0, 3, 12};
    sol.moveZeroes(nums1);
    for (int x : nums1) cout << x << " ";
    cout << endl;  // Output: 1 3 12 0 0

    vector<int> nums2 = {0};
    sol.moveZeroes(nums2);
    for (int x : nums2) cout << x << " ";
    cout << endl;  // Output: 0

    return 0;
}