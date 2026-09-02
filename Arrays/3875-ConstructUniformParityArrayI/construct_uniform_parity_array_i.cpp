// LeetCode 3875 - Construct Uniform Parity Array I
// Approach: Brain Teaser (Parity Math)
// Time: O(1) | Space: O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        return true;
    }
};

int main() {
    Solution sol;

    vector<int> nums1a = {2, 3};
    cout << boolalpha << sol.uniformArray(nums1a) << endl; // true

    vector<int> nums1b = {4, 6};
    cout << boolalpha << sol.uniformArray(nums1b) << endl; // true

    return 0;
}
