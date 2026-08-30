// LeetCode 2091 - Removing Minimum and Maximum From Array
// Approach: Find Min/Max Index + Compare 3 Deletion Strategies
// Time: O(n) | Space: O(1)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minIdx = 0, maxIdx = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] < nums[minIdx]) minIdx = i;
            if (nums[i] > nums[maxIdx]) maxIdx = i;
        }

        int i = min(minIdx, maxIdx);
        int j = max(minIdx, maxIdx);

        int bothFront = j + 1;
        int bothBack = n - i;
        int oneEach = (i + 1) + (n - j);

        return min({bothFront, bothBack, oneEach});
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {2, 10, 7, 5, 4, 1, 8, 6};
    cout << sol.minimumDeletions(nums1) << endl; // 5

    vector<int> nums2 = {0, -4, 19, 1, 8, -2, -3, 5};
    cout << sol.minimumDeletions(nums2) << endl; // 3

    vector<int> nums3 = {101};
    cout << sol.minimumDeletions(nums3) << endl; // 1

    return 0;
}
