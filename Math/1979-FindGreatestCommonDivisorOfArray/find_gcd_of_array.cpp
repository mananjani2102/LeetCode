// LeetCode 1979 - Find Greatest Common Divisor of Array
// Approach: Euclidean Algorithm on Min and Max
// Time: O(n + log(min(a,b))) | Space: O(1)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findGCD(vector<int>& nums) {

        int smallest = *min_element(nums.begin(), nums.end());
        int largest = *max_element(nums.begin(), nums.end());

        return __gcd(smallest, largest);
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {2, 5, 6, 9, 10};
    cout << sol.findGCD(nums1) << endl; // 2

    vector<int> nums2 = {7, 5, 6, 8, 3};
    cout << sol.findGCD(nums2) << endl; // 1

    vector<int> nums3 = {3, 3};
    cout << sol.findGCD(nums3) << endl; // 3

    return 0;
}
