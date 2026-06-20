// LeetCode 26 - Remove Duplicates from Sorted Array
// Approach: Two Pointers
// Time: O(n) | Space: O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1;

        for (int i = 1; i < (int)nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                nums[k] = nums[i];
                k++;
            }
        }

        return k;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 1, 2};
    int k1 = sol.removeDuplicates(nums1);
    cout << "k = " << k1 << " → ";
    for (int i = 0; i < k1; i++) cout << nums1[i] << " ";
    cout << endl; // k=2 → 1 2

    vector<int> nums2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int k2 = sol.removeDuplicates(nums2);
    cout << "k = " << k2 << " → ";
    for (int i = 0; i < k2; i++) cout << nums2[i] << " ";
    cout << endl; // k=5 → 0 1 2 3 4

    return 0;
}
