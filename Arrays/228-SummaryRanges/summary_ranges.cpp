// LeetCode 228 - Summary Ranges
// Approach: Linear Scan
// Time: O(n) | Space: O(1) extra

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int start = nums[i];

            while (i + 1 < n && nums[i + 1] == nums[i] + 1) {
                i++;
            }

            int end = nums[i];

            if (start == end) {
                ans.push_back(to_string(start));
            } else {
                ans.push_back(to_string(start) + "->" + to_string(end));
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {0, 1, 2, 4, 5, 7};
    vector<string> r1 = sol.summaryRanges(nums1);
    for (string s : r1) cout << s << " ";
    cout << endl; // 0->2 4->5 7

    vector<int> nums2 = {0, 2, 3, 4, 6, 8, 9};
    vector<string> r2 = sol.summaryRanges(nums2);
    for (string s : r2) cout << s << " ";
    cout << endl; // 0 2->4 6 8->9

    return 0;
}
