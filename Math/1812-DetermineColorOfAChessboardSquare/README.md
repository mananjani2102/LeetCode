<div align="center">

# 1812. Determine Color of a Chessboard Square

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Math-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Parity_Check-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given chessboard coordinates like "a1", return true if the square is white, false if black.

---

## Examples

| Input | Output |
|-------|--------|
| "a1" | false |
| "h3" | true |
| "c7" | false |

---

## Approach - Parity Check (column + row)

"h3":
col = 'h'-'a' = 7
row = '3'-'1' = 2
(7-2) % 2 = 5 % 2 = 1 → true (white) ✓

"a1":
col = 'a'-'a' = 0
row = '1'-'1' = 0
(0-0) % 2 = 0 → false (black) ✓


- Chessboard pe color pattern **alternating** hota hai — ye column aur row index dono ki **parity (odd/even)** pe depend karta hai
- Column (`a-h`) ko 0-7 me convert karo, row (`1-8`) ko 0-7 me convert karo
- Agar `(col - row) % 2` **non-zero** hai to square white hai, warna black
- Ye ek **mathematical pattern** hai jo chessboard ke checkerboard structure se aata hai

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
    bool squareIsWhite(string coordinates) {
        return ((coordinates[0] - 'a') - (coordinates[1] - '1')) % 2;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/determine-color-of-a-chessboard-square/)
