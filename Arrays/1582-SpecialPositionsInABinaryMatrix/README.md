<div align="center">

# 1582. Special Positions in a Binary Matrix

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Arrays-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Row_Col_Precomputation-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Binary matrix `mat` mein **special position** wo hoti hai jahan:
- `mat[i][j] == 1` ho
- Usi row `i` aur column `j` ke baaki sab elements `0` hon

Aisi kitni special positions hain — return karo.

---

## Examples

| Input | Output | Explanation |
|-------|--------|-------------|
| `[[1,0,0],[0,0,1],[1,0,0]]` | `1` | Sirf `(1,2)` special hai |
| `[[1,0,0],[0,1,0],[0,0,1]]` | `3` | `(0,0)`, `(1,1)`, `(2,2)` teeno special |

---

## Approach — Row & Column Sum Precomputation

```
mat = [[1,0,0],
       [0,0,1],
       [1,0,0]]

Step 1 - Har row aur col ke 1s count karo:
  row = [1, 1, 1]
  col = [2, 0, 1]

Step 2 - Special check karo:
  (0,0): mat=1, row[0]=1, col[0]=2 → col!=1 ✗
  (1,2): mat=1, row[1]=1, col[2]=1 → ✓  count=1
  (2,0): mat=1, row[2]=1, col[0]=2 → col!=1 ✗

Answer: 1 ✓
```

- Pehle pass mein row aur col sums compute karo
- Dusre pass mein check karo: `mat[i][j]==1` AND `row[i]==1` AND `col[j]==1`
- Yeh O(m×n) mein ho jata hai — koi extra traversal nahi

---

## Complexity

| | |
|---|---|
| Time | O(m × n) |
| Space | O(m + n) |

---

## Solution

```cpp
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<int> row(m, 0);
        vector<int> col(n, 0);

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (mat[i][j] == 1) { row[i]++; col[j]++; }

        int count = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (mat[i][j] == 1 && row[i] == 1 && col[j] == 1)
                    count++;

        return count;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/special-positions-in-a-binary-matrix/)