<div align="center">

# 37. Sudoku Solver

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Arrays-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Backtracking-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Fill the empty (`.`) cells of a 9x9 Sudoku board so that every row, column, and 3x3 sub-box contains digits 1-9 exactly once. It is guaranteed the board has exactly one solution.

---

## Examples

| Input | Output |
|-------|--------|
| partially filled board (see above) | fully solved board where row0 = [5,3,4,6,7,8,9,1,2] |

---

## Approach - Backtracking
board row0 = [5,3,.,.,7,.,.,.,.]

find first empty cell → (0,2)
try c='1': row0 ok, col2 ok, box(0,0) ok → valid → place 1, recurse into (0,3)
  ... recursion goes deep, filling later cells ...
  eventually some far-away cell finds NO valid digit 1-9
  → that call returns false → backtrack: undo it, try its next candidate
  ... backtracking keeps bubbling up until (0,2)'s '1' itself gets undone
try c='2','3': also fail eventually deeper in the tree (same bubbling)
try c='4': row0 ok, col2 ok, box(0,0) ok → valid → place 4, recurse into (0,3)
  this branch never hits a dead end — rest of board fills successfully

(0,2) stays '4' → matches expected output ✓
(full trace has exponential branches, so this shows only the winning path)


- Row-major order me **pehla empty cell (`.`)** dhoondo
- Us cell ke liye digit `1` se `9` tak try karo — har digit ke liye `isValid()` check karo (same row, same column, same 3x3 box me pehle se na ho)
- Agar digit valid hai to place karke **recursively agle empty cell** ke liye `solve()` call karo
- Agar recursive call `true` return kare (aage sab successfully fill ho gaya) to upar bhi `true` return kar do
- Agar current cell ke liye **koi bhi digit valid nahi milta**, to `false` return karo — isse **backtrack** hota hai: pichla cell apna digit undo (`'.'`) karke apna agla candidate try karta hai
- Jab koi bhi empty cell na bache (poori loop khatam), to `true` return karo — board already in-place solved ho chuka hai

---

## Complexity

| | |
|---|---|
| Time | O(9^(n×n)) worst case |
| Space | O(n×n) recursion stack |

---

## Solution

```cpp
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

private:
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; c++) {
                        if (isValid(board, i, j, c)) {
                            board[i][j] = c;
                            if (solve(board)) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == c) return false;
            if (board[i][col] == c) return false;
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false;
        }
        return true;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/sudoku-solver/)
