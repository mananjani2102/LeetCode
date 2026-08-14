// LeetCode 3507 - Minimum Pair Removal to Sort Array I
// Approach: Simulation
// Time: O(n^3) worst case (n merges, each O(n) scan + O(n) check) | Space: O(n)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isNonDecreasing(vector<int>& nums) {
        for (int i = 1; i < (int)nums.size(); i++) {
            if (nums[i] < nums[i - 1]) return false;
        }
        return true;
    }

    int minimumPairRemoval(vector<int>& nums) {
        int operations = 0;

        while (!isNonDecreasing(nums)) {
            int minSum = INT_MAX;
            int minIdx = -1;

            for (int i = 0; i < (int)nums.size() - 1; i++) {
                int sum = nums[i] + nums[i + 1];
                if (sum < minSum) {
                    minSum = sum;
                    minIdx = i;
                }
            }

            nums[minIdx] = nums[minIdx] + nums[minIdx + 1];
            nums.erase(nums.begin() + minIdx + 1);

            operations++;
        }

        return operations;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {5, 2, 3, 1};
    cout << sol.minimumPairRemoval(nums1) << endl; // 2

    vector<int> nums2 = {1, 2, 2};
    cout << sol.minimumPairRemoval(nums2) << endl; // 0

    return 0;
}
