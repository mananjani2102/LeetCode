// LeetCode 27 - Remove Element
// Approach: Two Pointers
// Time: O(n) | Space: O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;

        for (int i = 0; i < (int)nums.size(); i++) {
            if (nums[i] != val) {
                nums[k] = nums[i];
                k++;
            }
        }

        return k;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {3, 2, 2, 3};
    int k1 = sol.removeElement(nums1, 3);
    cout << "k = " << k1 << " → ";
    for (int i = 0; i < k1; i++) cout << nums1[i] << " ";
    cout << endl; // k=2 → 2 2

    vector<int> nums2 = {0, 1, 2, 2, 3, 0, 4, 2};
    int k2 = sol.removeElement(nums2, 2);
    cout << "k = " << k2 << " → ";
    for (int i = 0; i < k2; i++) cout << nums2[i] << " ";
    cout << endl; // k=5 → 0 1 3 0 4

    return 0;
}
