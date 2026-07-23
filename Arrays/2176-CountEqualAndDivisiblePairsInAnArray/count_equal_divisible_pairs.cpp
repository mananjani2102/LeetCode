// LeetCode 2176 - Count Equal and Divisible Pairs in an Array
// Approach: Brute Force Nested Loops
// Time: O(n^2) | Space: O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int count = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] == nums[j] && (i * j) % k == 0) {
                    count++;
                }
            }
        }

        return count;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {3, 1, 2, 2, 2, 1, 3};
    cout << sol.countPairs(nums1, 2) << endl; // 4

    vector<int> nums2 = {1, 2, 3, 4};
    cout << sol.countPairs(nums2, 1) << endl; // 0

    return 0;
}
