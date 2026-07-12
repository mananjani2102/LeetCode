<div align="center">

# 566. Reshape the Matrix

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Arrays-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Flatten_Index_Mapping-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given m x n matrix mat and target dimensions r x c, reshape the matrix keeping row-traversal order. If not possible, return original matrix.

---

## Examples

| Input | Output |
|-------|--------|
| mat=[[1,2],[3,4]], r=1, c=4 | [[1,2,3,4]] |
| mat=[[1,2],[3,4]], r=2, c=4 | [[1,2],[3,4]] (invalid, unchanged) |

---

## Approach - Flatten Index Mapping
mat = [[1,2],[3,4]]   r=1, c=4
m=2, n=2 → mn=4, rc=4 ✓ valid
Flatten index mapping:
i=0: mat[0/2][0%2]=mat[0][0]=1 → result[0/4][0%4]=result[0][0]=1
i=1: mat[1/2][1%2]=mat[0][1]=2 → result[0/4][1%4]=result[0][1]=2
i=2: mat[2/2][2%2]=mat[1][0]=3 → result[0/4][2%4]=result[0][2]=3
i=3: mat[3/2][3%2]=mat[1][1]=4 → result[0/4][3%4]=result[0][3]=4
Result = [[1,2,3,4]] ✓

- Pehle check karo `m*n == r*c` — warna reshape possible nahi, original return karo
- Sabhi elements ko ek **linear index** `i` (0 se `m*n-1`) ke through treat karo
- Original position: `mat[i/n][i%n]`
- New position: `result[i/c][i%c]`
- Isse manually row-column track karne ki zaroorat nahi

---

## Complexity

| | |
|---|---|
| Time | O(m × n) |
| Space | O(r × c) for output matrix |

---

## Solution

```cpp
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();

        if (m * n != r * c) return mat;

        vector<vector<int>> result(r, vector<int>(c));

        for (int i = 0; i < m * n; i++) {
            result[i / c][i % c] = mat[i / n][i % n];
        }

        return result;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/reshape-the-matrix/)
