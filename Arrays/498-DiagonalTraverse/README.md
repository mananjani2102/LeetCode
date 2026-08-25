<div align="center">

# 498. Diagonal Traverse

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Arrays-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Diagonal_Simulation-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given an m x n matrix mat, return all elements of the matrix in diagonal order (alternating up-right and down-left direction per diagonal).

---

## Examples

| Input | Output |
|-------|--------|
| [[1,2,3],[4,5,6],[7,8,9]] | [1,2,4,7,5,3,6,8,9] |
| [[1,2],[3,4]] | [1,2,3,4] |

---

## Approach - Diagonal Direction Simulation
mat = [[1,2,3],[4,5,6],[7,8,9]], m=3,n=3
row=0,col=0,up=true

Diagonal1(up): push 1(0,0), row=-1,col=1 → row<0, stop
  col==n? no(1!=3) → row++ → row=0. up=false

Diagonal2(down): push 2(0,1),row=1,col=0; push 4(1,0),row=2,col=-1 → col<0, stop
  row==m? no(2!=3) → col++ → col=0. up=true

Diagonal3(up): push 7(2,0),row=1,col=1; push 5(1,1),row=0,col=2; push 3(0,2),row=-1,col=3 → row<0, stop
  col==n? yes(3==3) → row+=2→row=1; col-- → col=2. up=false

Diagonal4(down): push 6(1,2),row=2,col=1; push 8(2,1),row=3,col=0 → row==m(3), stop
  row==m? yes → col+=2→col=2; row-- → row=2. up=true

Diagonal5(up): push 9(2,2),row=1,col=3 → col==n, stop
  result.size()=9=m*n → loop ends

Result = [1,2,4,7,5,3,6,8,9] ✓


- Ek `row`, `col` pointer aur ek `up` boolean rakho jo batata hai current diagonal **upar-right** ki taraf ja rahi hai ya **neeche-left** ki taraf
- Jab `up=true`: jab tak `row>=0 && col<n` hai, element push karte jao aur `row--, col++` karo (upar-right diagonal move)
- Jab `up=false`: jab tak `col>=0 && row<m` hai, element push karte jao aur `row++, col--` karo (neeche-left diagonal move)
- Diagonal khatam hone ke baad **boundary correction** karni padti hai — agar right edge (`col==n`) se tak gaye ho to `row+=2, col--` (ek row neeche shift), warna sirf `row++`. Similarly left/bottom edge ke liye `col+=2, row--` ya sirf `col++`
- Yeh correction isliye zaroori hai kyunki agli diagonal ka starting point pichli diagonal ke last valid cell se **ek row/col shift** karke milta hai, na ki wahi cell se
- Har diagonal ke baad `up` ko **flip** kar do, aur jab tak `result` me `m*n` elements na aa jaaye tab tak yeh process repeat hota rahta hai

---

## Complexity

| | |
|---|---|
| Time | O(m×n) |
| Space | O(1) extra (excluding output array) |

---

## Solution

```cpp
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> result;
        int row = 0, col = 0;
        bool up = true;

        while ((int)result.size() < m * n) {
            if (up) {
                while (row >= 0 && col < n) {
                    result.push_back(mat[row][col]);
                    row--;
                    col++;
                }
                if (col == n) { row += 2; col--; }
                else { row++; }
            } else {
                while (col >= 0 && row < m) {
                    result.push_back(mat[row][col]);
                    row++;
                    col--;
                }
                if (row == m) { col += 2; row--; }
                else { col++; }
            }
            up = !up;
        }

        return result;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/diagonal-traverse/)
