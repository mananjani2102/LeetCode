// LeetCode 16 - 3Sum Closest
// Approach: Sort + Two Pointers
// Time: O(n^2) | Space: O(1)

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int closestSum = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n - 2; i++) {
            int left = i + 1, right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (abs(sum - target) < abs(closestSum - target)) {
                    closestSum = sum;
                }

                if (sum == target) {
                    return sum;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        return closestSum;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {-1, 2, 1, -4};
    cout << sol.threeSumClosest(nums1, 1) << endl; // 2

    vector<int> nums2 = {0, 0, 0};
    cout << sol.threeSumClosest(nums2, 1) << endl; // 0

    return 0;
}
