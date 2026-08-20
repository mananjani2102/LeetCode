<div align="center">

# 73. Set Matrix Zeroes

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Arrays-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-In_Place_Marking-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given an m x n matrix, if an element is 0, set its entire row and column to 0. Must be done in-place, ideally with O(1) extra space.

---

## Examples

| Input | Output |
|-------|--------|
| [[1,1,1],[1,0,1],[1,1,1]] | [[1,0,1],[0,0,0],[1,0,1]] |
| [[0,1,2,0],[3,4,5,2],[1,3,1,5]] | [[0,0,0,0],[0,4,5,0],[0,3,1,0]] |

---

## Approach - In Place Marking using First Row/Column
matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]

Step A: check first row/col for zero before overwriting
  firstRowZero=true (matrix[0][0]=0 and matrix[0][3]=0)
  firstColZero=true (matrix[0][0]=0)

Step B: scan rest of matrix (i=1..2, j=1..2), mark first row/col as flags
  matrix[1][j]: 4,5,2 → none zero
  matrix[2][j]: 3,1,5 → none zero
  (no inner zeros found, so first row/col stay as they were: [0,1,2,0] / col0=[0,3,1])

Step C: use those flags (matrix[i][0], matrix[0][j]) to zero out inner cells
  matrix[1][1]: row-flag matrix[1][0]=3(no), col-flag matrix[0][1]=1(no) → stays 4
  matrix[1][2]: matrix[1][0]=3(no), matrix[0][2]=2(no) → stays 5
  matrix[2][1]: matrix[2][0]=1(no), matrix[0][1]=1(no) → stays 3
  matrix[2][2]: matrix[2][0]=1(no), matrix[0][2]=2(no) → stays 1

Step D: apply firstRowZero/firstColZero flags
  firstRowZero=true → row0 = [0,0,0,0]
  firstColZero=true → col0 = [0,0,0] (all rows' first element)

Final: [[0,0,0,0],[0,4,5,0],[0,3,1,0]] ✓


- Extra `O(m+n)` array banane ke bajaye, **matrix ki hi first row aur first column** ko marker ki tarah use karo — lekin unhe overwrite karne se pehle unka original zero-status ek boolean me save kar lo (`firstRowZero`, `firstColZero`)
- Phir matrix ke **baaki part (i=1..m-1, j=1..n-1)** ko scan karo — jaha bhi 0 mile, uske row ka first cell (`matrix[i][0]`) aur column ka first cell (`matrix[0][j]`) ko 0 kar do (yeh markers ban jate hai)
- Ab dobara wahi range traverse karo aur har cell ko check karo — agar uska row-marker ya column-marker 0 hai to us cell ko 0 kar do
- Aakhir me saved `firstRowZero`/`firstColZero` flags ke hisaab se **first row aur first column** ko khud zero karo
- Isse koi extra data structure nahi lagti, matrix khud apne markers store karti hai — **O(1) extra space**

---

## Complexity

| | |
|---|---|
| Time | O(m×n) |
| Space | O(1) |

---

## Solution

```cpp
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool firstRowZero = false, firstColZero = false;

        for (int j = 0; j < n; j++)
            if (matrix[0][j] == 0) firstRowZero = true;

        for (int i = 0; i < m; i++)
            if (matrix[i][0] == 0) firstColZero = true;

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        if (firstRowZero)
            for (int j = 0; j < n; j++) matrix[0][j] = 0;

        if (firstColZero)
            for (int i = 0; i < m; i++) matrix[i][0] = 0;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/set-matrix-zeroes/)
