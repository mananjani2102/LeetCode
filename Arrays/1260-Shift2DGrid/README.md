<div align="center">

# 1260. Shift 2D Grid

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Arrays-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Flatten_Index_Mapping-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given m x n grid and integer k, shift the grid k times (each shift moves every element one position forward, wrapping around). Return the shifted grid.

---

## Examples

| Input | Output |
|-------|--------|
| grid=[[1,2,3],[4,5,6],[7,8,9]], k=1 | [[9,1,2],[3,4,5],[6,7,8]] |
| grid=[[1,2,3],[4,5,6],[7,8,9]], k=9 | [[1,2,3],[4,5,6],[7,8,9]] (unchanged, full cycle) |

---

## Approach - Flatten Index Mapping with Modulo

grid = [[1,2,3],[4,5,6],[7,8,9]] k=1
m=3, n=3, total=9

k = 1 % 9 = 1

For element at (0,0)=1:
oldIndex = 0*3+0 = 0
newIndex = (0+1)%9 = 1
newRow=1/3=0, newCol=1%3=1
ans[0][1] = 1

For element at (2,2)=9 (last element):
oldIndex = 2*3+2 = 8
newIndex = (8+1)%9 = 0
newRow=0/3=0, newCol=0%3=0
ans[0][0] = 9

Result = [[9,1,2],[3,4,5],[6,7,8]] ✓


- Har grid element ko ek **linear/flattened index** me convert karo: `i*n + j`
- `k` shifts ke baad naya position: `(oldIndex + k) % total` — modulo se **wraparound** handle ho jata hai
- Pehle `k = k % total` kar lo taaki agar `k` bahut bada ho (jaise multiple full cycles) to unnecessary iterations avoid ho
- Naya flat index se wapas 2D position nikalo: `newRow = newIndex/n`, `newCol = newIndex%n`

---

## Complexity

| | |
|---|---|
| Time | O(m × n) |
| Space | O(m × n) for output |

---

## Solution

```cpp
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {

        int m = grid.size();
        int n = grid[0].size();

        int total = m * n;

        k = k % total;

        vector<vector<int>> ans(m, vector<int>(n));

        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                int oldIndex = i * n + j;

                int newIndex = (oldIndex + k) % total;

                int newRow = newIndex / n;
                int newCol = newIndex % n;

                ans[newRow][newCol] = grid[i][j];
            }
        }

        return ans;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/shift-2d-grid/)
