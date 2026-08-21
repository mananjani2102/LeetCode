// LeetCode 56 - Merge Intervals
// Approach: Sort + Merge
// Time: O(n log n) | Space: O(n)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;

        for (auto& interval : intervals) {
            if (result.empty() || result.back()[1] < interval[0]) {
                result.push_back(interval);
            } else {
                result.back()[1] = max(result.back()[1], interval[1]);
            }
        }

        return result;
    }
};

void printResult(vector<vector<int>>& res) {
    for (auto& iv : res) cout << "[" << iv[0] << "," << iv[1] << "] ";
    cout << endl;
}

int main() {
    Solution sol;

    vector<vector<int>> i1 = {{1,3},{2,6},{8,10},{15,18}};
    auto r1 = sol.merge(i1);
    printResult(r1); // [1,6] [8,10] [15,18]

    vector<vector<int>> i2 = {{1,4},{4,5}};
    auto r2 = sol.merge(i2);
    printResult(r2); // [1,5]

    vector<vector<int>> i3 = {{4,7},{1,4}};
    auto r3 = sol.merge(i3);
    printResult(r3); // [1,7]

    return 0;
}
