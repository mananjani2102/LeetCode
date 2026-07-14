// LeetCode 217 - Contains Duplicate
// Approach: HashSet
// Time: O(n) | Space: O(n)

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;

        for (int num : nums) {
            if (seen.count(num)) {
                return true;
            }
            seen.insert(num);
        }

        return false;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 2, 3, 1};
    cout << sol.containsDuplicate(nums1) << endl; // 1 (true)

    vector<int> nums2 = {1, 2, 3, 4};
    cout << sol.containsDuplicate(nums2) << endl; // 0 (false)

    vector<int> nums3 = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    cout << sol.containsDuplicate(nums3) << endl; // 1 (true)

    return 0;
}
