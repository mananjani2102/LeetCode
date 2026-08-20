<div align="center">

# 36. Valid Sudoku

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Arrays-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-HashSet-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Determine if a 9x9 Sudoku board is valid — filled cells must not repeat within any row, column, or 3x3 sub-box.

---

## Examples

| Input | Output |
|-------|--------|
| board with 5 at [0][0] (valid) | true |
| same board with 8 at [0][0] (duplicate in top-left box) | false |

---

## Approach - HashSet
board[0][0]='8', board[3][0]='8'

i=0,j=0,val='8':
  rowKey="row08", colKey="col08", boxKey="box008"
  seen me nahi hai → insert all three → seen={row08,col08,box008}

... (kai cells baad) ...

i=3,j=0,val='8':
  rowKey="row38", colKey="col08", boxKey="box108"
  colKey="col08" already seen (from i=0,j=0) → return false

Answer = false ✓ (same column me do baar 8)


- Har filled cell ke liye **teeni unique keys** banao — row ke liye (`row+index+value`), column ke liye (`col+index+value`), aur box ke liye (`box+boxRow+boxCol+value`) — box ka index `i/3` aur `j/3` se milta hai
- Ek single `unordered_set<string>` me saari keys daalo — agar koi bhi key **pehle se maujood** hai to matlab wahi value row/column/box me repeat ho rahi hai → seedha `false` return karo
- Agar koi conflict na mile to teeno keys insert karke aage badho
- `.` (empty cell) ko skip karo — sirf filled cells hi validate karni hai
- Board size fix (9x9) hai isliye time/space **O(1)** treat kiya jata hai (constant 81 cells)

---

## Complexity

| | |
|---|---|
| Time | O(1) |
| Space | O(1) |

---

## Solution

```cpp
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> seen;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char val = board[i][j];
                if (val == '.') continue;

                string rowKey = "row" + to_string(i) + val;
                string colKey = "col" + to_string(j) + val;
                string boxKey = "box" + to_string(i / 3) + to_string(j / 3) + val;

                if (seen.count(rowKey) || seen.count(colKey) || seen.count(boxKey))
                    return false;

                seen.insert(rowKey);
                seen.insert(colKey);
                seen.insert(boxKey);
            }
        }

        return true;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/valid-sudoku/)
