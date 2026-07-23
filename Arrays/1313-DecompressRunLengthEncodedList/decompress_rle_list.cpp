// LeetCode 1313 - Decompress Run-Length Encoded List
// Approach: Simple Iteration
// Time: O(n) | Space: O(n)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> result;

        for (int i = 0; i < (int)nums.size(); i += 2) {
            int freq = nums[i];
            int val = nums[i + 1];

            for (int j = 0; j < freq; j++) {
                result.push_back(val);
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 2, 3, 4};
    vector<int> r1 = sol.decompressRLElist(nums1);
    for (int x : r1) cout << x << " ";
    cout << endl; // 2 4 4 4

    vector<int> nums2 = {1, 1, 2, 3};
    vector<int> r2 = sol.decompressRLElist(nums2);
    for (int x : r2) cout << x << " ";
    cout << endl; // 1 3 3

    return 0;
}
