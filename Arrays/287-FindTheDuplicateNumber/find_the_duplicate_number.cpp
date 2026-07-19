// LeetCode 287 - Find the Duplicate Number
// Approach: Floyd's Cycle Detection (treating array as linked list)
// Time: O(n) | Space: O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int slow = nums[0];
        int fast = nums[0];

        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        int slow2 = nums[0];

        while (slow != slow2) {
            slow = nums[slow];
            slow2 = nums[slow2];
        }

        return slow;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 3, 4, 2, 2};
    cout << sol.findDuplicate(nums1) << endl; // 2

    vector<int> nums2 = {3, 1, 3, 4, 2};
    cout << sol.findDuplicate(nums2) << endl; // 3

    vector<int> nums3 = {3, 3, 3, 3, 3};
    cout << sol.findDuplicate(nums3) << endl; // 3

    return 0;
}
