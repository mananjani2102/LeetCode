// LeetCode 18 - 4Sum
// Approach: Sort + Two Pointers (Extension of 3Sum)
// Time: O(n^3) | Space: O(1) excluding output

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int left = j + 1, right = n - 1;

                while (left < right) {
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                    if (sum == target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});

                        while (left < right && nums[left] == nums[left + 1]) left++;
                        while (left < right && nums[right] == nums[right - 1]) right--;

                        left++;
                        right--;
                    }
                    else if (sum < target) {
                        left++;
                    }
                    else {
                        right--;
                    }
                }
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 0, -1, 0, -2, 2};
    vector<vector<int>> r1 = sol.fourSum(nums1, 0);
    for (auto& q : r1) {
        cout << "[" << q[0] << "," << q[1] << "," << q[2] << "," << q[3] << "] ";
    }
    cout << endl; // [-2,-1,1,2] [-2,0,0,2] [-1,0,0,1]

    vector<int> nums2 = {2, 2, 2, 2, 2};
    vector<vector<int>> r2 = sol.fourSum(nums2, 8);
    for (auto& q : r2) {
        cout << "[" << q[0] << "," << q[1] << "," << q[2] << "," << q[3] << "] ";
    }
    cout << endl; // [2,2,2,2]

    return 0;
}
