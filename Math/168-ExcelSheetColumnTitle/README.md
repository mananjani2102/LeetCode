<div align="center">

# 168. Excel Sheet Column Title

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Math-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Base_26_Conversion-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given integer columnNumber, return its Excel column title (A=1, B=2, ..., Z=26, AA=27, ...).

---

## Examples

| Input | Output |
|-------|--------|
| 1 | "A" |
| 28 | "AB" |
| 701 | "ZY" |

---

## Approach - Base-26 Conversion (1-indexed)
columnNumber = 28
Step 1: columnNumber-- = 27
27 % 26 = 1 → 'A'+1 = 'B' → result="B"
27 / 26 = 1
Step 2: columnNumber-- = 0
0 % 26 = 0 → 'A'+0 = 'A' → result="BA"
0 / 26 = 0
Loop ends (columnNumber==0)
Reverse "BA" → "AB" ✓

- Ye **base-26** system hai lekin **1-indexed** (0-indexed nahi jaisa normal base conversion)
- Isliye har step pe pehle `columnNumber--` karo taaki 0-indexed ban jaye
- Fir `% 26` se current digit nikalo aur `'A' + digit` se character banao
- `/26` se aage badho
- End me result **reverse** karo kyunki digits ulte order me bane the

---

## Complexity

| | |
|---|---|
| Time | O(log n) |
| Space | O(1) |

---

## Solution

```cpp
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";

        while (columnNumber > 0) {
            columnNumber--;
            char ch = 'A' + (columnNumber % 26);
            result += ch;
            columnNumber /= 26;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/excel-sheet-column-title/)
