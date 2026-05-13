// LeetCode 15 - 3Sum
// Approach: Sort + Two Pointers
// Time: O(n^2) | Space: O(1)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = (int)nums.size();

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});

                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;

                    left++;
                    right--;
                }
                else if (sum < 0) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> res1 = sol.threeSum(nums1);
    for (auto& triplet : res1) {
        cout << "[" << triplet[0] << "," << triplet[1] << "," << triplet[2] << "] ";
    }
    cout << endl; // [-1,-1,2] [-1,0,1]

    vector<int> nums2 = {0, 1, 1};
    vector<vector<int>> res2 = sol.threeSum(nums2);
    cout << "Result size: " << res2.size() << endl; // 0

    vector<int> nums3 = {0, 0, 0};
    vector<vector<int>> res3 = sol.threeSum(nums3);
    for (auto& triplet : res3) {
        cout << "[" << triplet[0] << "," << triplet[1] << "," << triplet[2] << "] ";
    }
    cout << endl; // [0,0,0]

    return 0;
}