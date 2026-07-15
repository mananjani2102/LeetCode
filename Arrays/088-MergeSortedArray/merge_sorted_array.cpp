// LeetCode 88 - Merge Sorted Array
// Approach: Two Pointers from Back
// Time: O(m+n) | Space: O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }

        while (j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
};

int main() {
    Solution sol;

    vector<int> nums1a = {1, 2, 3, 0, 0, 0};
    vector<int> nums2a = {2, 5, 6};
    sol.merge(nums1a, 3, nums2a, 3);
    for (int x : nums1a) cout << x << " ";
    cout << endl; // 1 2 2 3 5 6

    vector<int> nums1b = {1};
    vector<int> nums2b = {};
    sol.merge(nums1b, 1, nums2b, 0);
    for (int x : nums1b) cout << x << " ";
    cout << endl; // 1

    vector<int> nums1c = {0};
    vector<int> nums2c = {1};
    sol.merge(nums1c, 0, nums2c, 1);
    for (int x : nums1c) cout << x << " ";
    cout << endl; // 1

    return 0;
}
