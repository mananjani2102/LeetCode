// LeetCode 2958 - Length of Longest Subarray With at Most K Frequency
// Approach: Sliding Window with HashMap
// Time: O(n) | Space: O(n)

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int left = 0;
        int maxLen = 0;

        for (int right = 0; right < (int)nums.size(); right++) {
            freq[nums[right]]++;

            while (freq[nums[right]] > k) {
                freq[nums[left]]--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 2, 3, 1, 2, 3, 1, 2};
    cout << sol.maxSubarrayLength(nums1, 2) << endl; // 6

    vector<int> nums2 = {1, 2, 1, 2, 1, 2, 1, 2};
    cout << sol.maxSubarrayLength(nums2, 1) << endl; // 2

    vector<int> nums3 = {5, 5, 5, 5, 5, 5, 5};
    cout << sol.maxSubarrayLength(nums3, 4) << endl; // 4

    return 0;
}
