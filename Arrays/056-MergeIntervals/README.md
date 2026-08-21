<div align="center">

# 56. Merge Intervals

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Arrays-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Sort_Merge-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given an array of intervals, merge all overlapping intervals and return an array of non-overlapping intervals covering all input intervals.

---

## Examples

| Input | Output |
|-------|--------|
| [[1,3],[2,6],[8,10],[15,18]] | [[1,6],[8,10],[15,18]] |
| [[1,4],[4,5]] | [[1,5]] |
| [[4,7],[1,4]] | [[1,7]] |

---

## Approach - Sort Merge
intervals = [[4,7],[1,4]]
Sort by start → [[1,4],[4,7]]

result = []
interval=[1,4]: result empty → push → result=[[1,4]]
interval=[4,7]: result.back()[1]=4, interval[0]=4 → 4 < 4 is false (overlap, touching counts)
  → merge: result.back()[1] = max(4,7) = 7 → result=[[1,7]]

Answer = [[1,7]] ✓


- Intervals ko **start value ke hisaab se sort** karo — isse overlapping ya touching intervals ek dusre ke paas aa jate hai
- Sorted list traverse karo — agar `result` empty hai ya **last merged interval ka end current interval ke start se strictly chota** hai, to koi overlap nahi, naya interval push kar do
- Warna overlap hai (ya touching hai, jaise `[1,4]` aur `[4,5]`) — to last interval ka `end` ko `max(last.end, current.end)` se update kar do, taaki dono interval ek me merge ho jaaye
- Ek hi pass me sorted array traverse karke saare overlaps merge ho jaate hai, kyunki sorting ke baad overlap sirf **consecutive intervals** ke beech hi possible hota hai

---

## Complexity

| | |
|---|---|
| Time | O(n log n) |
| Space | O(n) |

---

## Solution

```cpp
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
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/merge-intervals/)
