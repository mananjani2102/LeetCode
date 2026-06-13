// LeetCode 2948 - Make Lexicographically Smallest Array by Swapping Elements
// Approach: Sort + Union-Find Style Grouping
// Time: O(n log n) | Space: O(n)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        sort(arr.begin(), arr.end());

        vector<int> ans(n);

        int start = 0;

        while (start < n) {
            int end = start;

            while (end + 1 < n &&
                   arr[end + 1].first - arr[end].first <= limit) {
                end++;
            }

            vector<int> indices;
            vector<int> values;

            for (int i = start; i <= end; i++) {
                indices.push_back(arr[i].second);
                values.push_back(arr[i].first);
            }

            sort(indices.begin(), indices.end());

            for (int i = 0; i < (int)indices.size(); i++) {
                ans[indices[i]] = values[i];
            }

            start = end + 1;
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> n1 = {1, 5, 3, 9, 8};
    vector<int> r1 = sol.lexicographicallySmallestArray(n1, 2);
    for (int x : r1) cout << x << " ";
    cout << endl; // 1 3 5 8 9

    vector<int> n2 = {1, 7, 6, 18, 2, 1};
    vector<int> r2 = sol.lexicographicallySmallestArray(n2, 3);
    for (int x : r2) cout << x << " ";
    cout << endl; // 1 6 7 18 1 2

    vector<int> n3 = {1, 7, 28, 19, 10};
    vector<int> r3 = sol.lexicographicallySmallestArray(n3, 3);
    for (int x : r3) cout << x << " ";
    cout << endl; // 1 7 28 19 10

    return 0;
}
