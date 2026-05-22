// LeetCode 219 - Contains Duplicate II
// Approach: HashMap (Index Tracking)
// Time: O(n) | Space: O(n)

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for (int i = 0; i < (int)nums.size(); i++) {
            if (mp.count(nums[i]) && i - mp[nums[i]] <= k) {
                return true;
            }

            mp[nums[i]] = i;
        }

        return false;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 2, 3, 1};
    cout << sol.containsNearbyDuplicate(nums1, 3) << endl; // 1 (true)

    vector<int> nums2 = {1, 0, 1, 1};
    cout << sol.containsNearbyDuplicate(nums2, 1) << endl; // 1 (true)

    vector<int> nums3 = {1, 2, 3, 1, 2, 3};
    cout << sol.containsNearbyDuplicate(nums3, 2) << endl; // 0 (false)

    return 0;
}
