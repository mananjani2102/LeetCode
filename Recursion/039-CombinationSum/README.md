<div align="center">

# 39. Combination Sum

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Recursion-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Backtracking-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given distinct integers candidates and target, return all unique combinations (numbers can repeat unlimited times) that sum to target.

---

## Examples

| Input | Output |
|-------|--------|
| candidates=[2,3,6,7], target=7 | [[2,2,3],[7]] |
| candidates=[2,3,5], target=8 | [[2,2,2,2],[2,3,3],[3,5]] |
| candidates=[2], target=1 | [] |

---

## Approach - Backtracking

candidates=[2,3,6,7] target=7

backtrack(target=7, start=0, current=[]):
try 2: current=[2], backtrack(target=5, start=0)
try 2: current=[2,2], backtrack(target=3, start=0)
try 2: current=[2,2,2], backtrack(target=1, start=0) → too small, backtrack
try 3: current=[2,2,3], backtrack(target=0) → FOUND [2,2,3] ✓
try 3: current=[2,3], backtrack(target=2, start=1)
... eventually explored, no valid path here
try 7: current=[7], backtrack(target=0) → FOUND [7] ✓

Result: [[2,2,3],[7]] ✓


- **Backtracking** se try karo har candidate ko current combination me add karna
- Same number **unlimited baar** use ho sakta hai, isliye recursive call me `start` index same rakho (i, na ki i+1)
- `target == 0` → valid combination mil gaya, result me add karo
- `target < 0` → invalid path, backtrack karo
- `current.pop_back()` se **backtrack** karo taaki agla candidate try kar sakein

---

## Complexity

| | |
|---|---|
| Time | O(2^target) worst case |
| Space | O(target) recursion depth |

---

## Solution

```cpp
class Solution {
public:
    void backtrack(vector<int>& candidates, int target, int start,
                    vector<int>& current, vector<vector<int>>& result) {

        if (target == 0) {
            result.push_back(current);
            return;
        }

        if (target < 0) return;

        for (int i = start; i < candidates.size(); i++) {
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
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/combination-sum/)
