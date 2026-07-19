// LeetCode 594 - Longest Harmonious Subsequence
// Approach: HashMap Frequency Count
// Time: O(n) | Space: O(n)

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {

        unordered_map<int, int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        int ans = 0;

        for (auto it : freq) {

            int num = it.first;

            if (freq.find(num + 1) != freq.end()) {

                int length = freq[num] + freq[num + 1];

                ans = max(ans, length);
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 3, 2, 2, 5, 2, 3, 7};
    cout << sol.findLHS(nums1) << endl; // 5

    vector<int> nums2 = {1, 2, 3, 4};
    cout << sol.findLHS(nums2) << endl; // 2

    vector<int> nums3 = {1, 1, 1, 1};
    cout << sol.findLHS(nums3) << endl; // 0

    return 0;
}
