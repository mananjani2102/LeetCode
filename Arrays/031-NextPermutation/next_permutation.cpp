// LeetCode 31 - Next Permutation
// Approach: Find Pivot + Swap + Reverse
// Time: O(n) | Space: O(1)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pivot = -1;

        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                pivot = i;
                break;
            }
        }

        if (pivot == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        for (int i = n - 1; i > pivot; i--) {
            if (nums[i] > nums[pivot]) {
                swap(nums[i], nums[pivot]);
                break;
            }
        }

        reverse(nums.begin() + pivot + 1, nums.end());
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 2, 3};
    sol.nextPermutation(nums1);
    for (int x : nums1) cout << x << " ";
    cout << endl; // 1 3 2

    vector<int> nums2 = {3, 2, 1};
    sol.nextPermutation(nums2);
    for (int x : nums2) cout << x << " ";
    cout << endl; // 1 2 3

    vector<int> nums3 = {1, 1, 5};
    sol.nextPermutation(nums3);
    for (int x : nums3) cout << x << " ";
    cout << endl; // 1 5 1

    return 0;
}
