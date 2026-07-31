// LeetCode 39 - Combination Sum
// Approach: Backtracking
// Time: O(2^target) worst case | Space: O(target) recursion depth

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void backtrack(vector<int>& candidates, int target, int start,
                    vector<int>& current, vector<vector<int>>& result) {

        if (target == 0) {
            result.push_back(current);
            return;
        }

        if (target < 0) return;

        for (int i = start; i < (int)candidates.size(); i++) {
            current.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i, current, result);
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;

        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, current, result);

        return result;
    }
};

int main() {
    Solution sol;

    vector<int> candidates1 = {2, 3, 6, 7};
    vector<vector<int>> r1 = sol.combinationSum(candidates1, 7);
    for (auto& combo : r1) {
        cout << "[";
        for (int x : combo) cout << x << " ";
        cout << "] ";
    }
    cout << endl; // [2 2 3 ] [7 ]

    vector<int> candidates2 = {2, 3, 5};
    vector<vector<int>> r2 = sol.combinationSum(candidates2, 8);
    for (auto& combo : r2) {
        cout << "[";
        for (int x : combo) cout << x << " ";
        cout << "] ";
    }
    cout << endl; // [2 2 2 2 ] [2 3 3 ] [3 5 ]

    return 0;
}
