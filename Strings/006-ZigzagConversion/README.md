<div align="center">

# 6. Zigzag Conversion

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Strings-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Simulate_Rows-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Write a string in **zigzag pattern** across `numRows` rows, then read line by line and return the result.
P   A   H   N   A   P   L   S   I   I   G  Y   I   R

---

## Examples

| Input | Output |
|-------|--------|
| s="PAYPALISHIRING", numRows=3 | "PAHNAPLSIIGYIR" |
| s="PAYPALISHIRING", numRows=4 | "PINALSIGYAHRPI" |
| s="A", numRows=1 | "A" |

---

## Approach — Simulate Rows
s = "PAYPALISHIRING"   numRows = 3
curRow=0, goingDown=false
P → rows[0]   curRow=0 → flip down → curRow=1

A → rows[1]   curRow=1 → curRow=2

Y → rows[2]   curRow=2 → flip up → curRow=1

P → rows[1]   curRow=1 → curRow=0

A → rows[0]   curRow=0 → flip down → curRow=1

...
rows[0] = "PAHN"

rows[1] = "APLSIIG"

rows[2] = "YIR"
Result = "PAHN" + "APLSIIG" + "YIR" = "PAHNAPLSIIGYIR" ✓

- Har row ke liye alag string rakho (`vector<string> rows`)
- Character ko current row me daalo
- Top (`row 0`) ya bottom (`row numRows-1`) pe pahuncho to direction flip karo
- Sabhi rows ko end me concatenate karo

---

## Complexity

| | |
|---|---|
| Time | O(n) |
| Space | O(n) |

---

## Solution

```cpp
// LeetCode 6 - Zigzag Conversion
// Approach: Simulate Rows
// Time: O(n) | Space: O(n)

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        vector<string> rows(numRows);
        int curRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[curRow] += c;
            if (curRow == 0 || curRow == numRows - 1) {
                goingDown = !goingDown;
            }
            curRow += goingDown ? 1 : -1;
        }

        string result = "";
        for (string row : rows) {
            result += row;
        }
        return result;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/zigzag-conversion/)
