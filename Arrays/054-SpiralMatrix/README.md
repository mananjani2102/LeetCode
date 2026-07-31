<div align="center">

# 54. Spiral Matrix

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Arrays-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Boundary_Tracking-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given m x n matrix, return all elements in spiral order (clockwise, starting from top-left).

---

## Examples

| Input | Output |
|-------|--------|
| [[1,2,3],[4,5,6],[7,8,9]] | [1,2,3,6,9,8,7,4,5] |
| [[1,2,3,4],[5,6,7,8],[9,10,11,12]] | [1,2,3,4,8,12,11,10,9,5,6,7] |

---

## Approach - Boundary Tracking (Top, Bottom, Left, Right)

matrix = [[1,2,3],[4,5,6],[7,8,9]]

top=0,bottom=2,left=0,right=2

Loop1:
Right across top row: 1,2,3 → top=1
Down right column: 6,9 → right=1
Left across bottom row: 8,7 → bottom=1
Up left column: 4 → left=1

Loop2 (top=1,bottom=1,left=1,right=1):
Right across: 5 → top=2
(bottom check: top>bottom now, skip)
(left check: skip)

Result: [1,2,3,6,9,8,7,4] then 5 → [1,2,3,6,9,8,7,4,5] ✓


- Four **boundaries** track karo: `top`, `bottom`, `left`, `right`
- Har iteration me chaar directions traverse karo: **left→right** (top row), **top→bottom** (right column), **right→left** (bottom row, agar valid ho), **bottom→top** (left column, agar valid ho)
- Har direction ke baad corresponding boundary ko andar shift karo
- Extra checks (`if top<=bottom`, `if left<=right`) zaroori hain taaki single row/column matrices me duplicate na ho

---

## Complexity

| | |
|---|---|
| Time | O(m × n) |
| Space | O(1) excluding output |

---

## Solution

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty()) return result;

        int top = 0, bottom = matrix.size() - 1;
        int left = 0, right = matrix[0].size() - 1;

        while (top <= bottom && left <= right) {

            for (int j = left; j <= right; j++) {
                result.push_back(matrix[top][j]);
            }
            top++;

            for (int i = top; i <= bottom; i++) {
                result.push_back(matrix[i][right]);
            }
            right--;

            if (top <= bottom) {
                for (int j = right; j >= left; j--) {
                    result.push_back(matrix[bottom][j]);
                }
                bottom--;
            }

            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    result.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return result;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/spiral-matrix/)
