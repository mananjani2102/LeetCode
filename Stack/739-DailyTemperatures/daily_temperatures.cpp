// LeetCode 739 - Daily Temperatures
// Approach: Monotonic Stack
// Time: O(n) | Space: O(n)

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() &&
                   temperatures[i] > temperatures[st.top()]) {
                int idx = st.top();
                st.pop();
                ans[idx] = i - idx;
            }
            st.push(i);
        }
        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> t1 = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> r1 = sol.dailyTemperatures(t1);
    for (int x : r1) cout << x << " ";
    cout << endl; // 1 1 4 2 1 1 0 0

    vector<int> t2 = {30, 40, 50, 60};
    vector<int> r2 = sol.dailyTemperatures(t2);
    for (int x : r2) cout << x << " ";
    cout << endl; // 1 1 1 0

    vector<int> t3 = {30, 60, 90};
    vector<int> r3 = sol.dailyTemperatures(t3);
    for (int x : r3) cout << x << " ";
    cout << endl; // 1 1 0

    return 0;
}
