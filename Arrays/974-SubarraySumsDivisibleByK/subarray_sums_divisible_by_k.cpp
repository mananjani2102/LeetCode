// LeetCode 974 - Subarray Sums Divisible by K
// Approach: Prefix Sum + HashMap of Remainders
// Time: O(n) | Space: O(k)

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> remainderCount;
        remainderCount[0] = 1;

        int prefixSum = 0;
        int count = 0;

        for (int num : nums) {
            prefixSum += num;
            int remainder = ((prefixSum % k) + k) % k;

            if (remainderCount.count(remainder)) {
                count += remainderCount[remainder];
            }

            remainderCount[remainder]++;
        }

        return count;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {4, 5, 0, -2, -3, 1};
    cout << sol.subarraysDivByK(nums1, 5) << endl; // 7

    vector<int> nums2 = {5};
    cout << sol.subarraysDivByK(nums2, 9) << endl; // 0

    return 0;
}
