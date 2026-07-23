// LeetCode 3513 - Number of Unique XOR Triplets I
// Approach: Bit Pattern Observation (Next Power of 2)
// Time: O(1) | Space: O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        if (n <= 2) return n;

        int highestBit = 32 - __builtin_clz(n);
        return 1 << highestBit;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 2};
    cout << sol.uniqueXorTriplets(nums1) << endl; // 2

    vector<int> nums2 = {3, 1, 2};
    cout << sol.uniqueXorTriplets(nums2) << endl; // 4

    return 0;
}
