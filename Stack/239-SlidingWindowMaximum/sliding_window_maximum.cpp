// LeetCode 239 - Sliding Window Maximum
// Approach: Monotonic Deque
// Time: O(n) | Space: O(k)

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> result;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);

            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 3, -1, -3, 5, 3, 6, 7};
    vector<int> r1 = sol.maxSlidingWindow(nums1, 3);
    for (int x : r1) cout << x << " ";
    cout << endl; // 3 3 5 5 6 7

    vector<int> nums2 = {1};
    vector<int> r2 = sol.maxSlidingWindow(nums2, 1);
    for (int x : r2) cout << x << " ";
    cout << endl; // 1

    return 0;
}
