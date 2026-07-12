<div align="center">

# 292. Nim Game

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Math-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Game_Theory_Pattern-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

In Nim Game, players alternately remove 1-3 stones, last stone remover wins. Given n stones, return true if you (going first) can win with optimal play.

---

## Examples

| Input | Output |
|-------|--------|
| 4 | false |
| 1 | true |
| 2 | true |

---

## Approach - Game Theory Pattern
n=1,2,3 → you can take all stones directly → win
n=4     → chahe tum 1,2, ya 3 lo, friend baaki (3,2,1) le kar jeet jayega → lose
n=5,6,7 → tum itne stones lo ki friend ke liye 4 bach jaye → win
n=8     → phir se losing position (multiple of 4)

- Pattern: agar `n` **4 ka multiple** hai to tum **hamesha haaroge** (optimal opponent ke against)
- Kyunki jo bhi tum lo (1-3), opponent bacha hua adjust karke tumhe fir se 4 ka multiple de sakta hai
- Warna (`n % 4 != 0`) tum jeet sakte ho — pehla move aisa lo ki opponent ko 4 ka multiple mil jaye
- Isliye simple formula: `return n % 4 != 0`

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
    bool canWinNim(int n) {
        return n % 4 != 0;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/nim-game/)
