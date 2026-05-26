// LeetCode 496 - Next Greater Element I
// Approach: Monotonic Stack + HashMap
// Time: O(n+m) | Space: O(n)

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> mp;

        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }
            if (st.empty()) {
                mp[nums2[i]] = -1;
            } else {
                mp[nums2[i]] = st.top();
            }
            st.push(nums2[i]);
        }
        vector<int> ans;
        for (int num : nums1) {
            ans.push_back(mp[num]);
        }
        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums1a = {4, 1, 2};
    vector<int> nums2a = {1, 3, 4, 2};
    vector<int> r1 = sol.nextGreaterElement(nums1a, nums2a);
    for (int x : r1) cout << x << " ";
    cout << endl; // -1 3 -1

    vector<int> nums1b = {2, 4};
    vector<int> nums2b = {1, 2, 3, 4};
    vector<int> r2 = sol.nextGreaterElement(nums1b, nums2b);
    for (int x : r2) cout << x << " ";
    cout << endl; // 3 -1

    return 0;
}
