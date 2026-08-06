// LeetCode 350 - Intersection of Two Arrays II
// Approach: HashMap Frequency Count
// Time: O(n+m) | Space: O(min(n,m))

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> freq;

        for (int num : nums1) {
            freq[num]++;
        }

        vector<int> result;

        for (int num : nums2) {
            if (freq[num] > 0) {
                result.push_back(num);
                freq[num]--;
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    vector<int> nums1a = {1, 2, 2, 1};
    vector<int> nums2a = {2, 2};
    vector<int> r1 = sol.intersect(nums1a, nums2a);
    for (int x : r1) cout << x << " ";
    cout << endl; // 2 2

    vector<int> nums1b = {4, 9, 5};
    vector<int> nums2b = {9, 4, 9, 8, 4};
    vector<int> r2 = sol.intersect(nums1b, nums2b);
    for (int x : r2) cout << x << " ";
    cout << endl; // 4 9 (order may vary)

    return 0;
}
