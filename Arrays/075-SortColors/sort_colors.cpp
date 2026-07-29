// LeetCode 75 - Sort Colors
// Approach: Dutch National Flag Algorithm (One Pass, Three Pointers)
// Time: O(n) | Space: O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1) {
                mid++;
            }
            else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {2, 0, 2, 1, 1, 0};
    sol.sortColors(nums1);
    for (int x : nums1) cout << x << " ";
    cout << endl; // 0 0 1 1 2 2

    vector<int> nums2 = {2, 0, 1};
    sol.sortColors(nums2);
    for (int x : nums2) cout << x << " ";
    cout << endl; // 0 1 2

    return 0;
}
