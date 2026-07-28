<div align="center">

# 1025. Divisor Game

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Math-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Parity_Game_Theory-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Alice and Bob alternately pick x (0<x<n, n%x==0) and replace n with n-x. Player who cannot move loses. Return true if Alice wins with optimal play.

---

## Examples

| Input | Output |
|-------|--------|
| 2 | true |
| 3 | false |

---

## Approach - Parity Game Theory

n=2 (even): Alice picks x=1 → n becomes 1 (odd)
Bob has n=1, no valid x (0<x<1 impossible) → Bob loses
Alice wins! true ✓

n=3 (odd): Alice must pick x=1 (only divisor <3) → n becomes 2 (even)
Bob picks x=1 → n becomes 1 (odd)
Alice has n=1, no moves → Alice loses
false ✓


- Ye ek **mathematical pattern** hai jo game theory se nikalta hai
- **n even ho to Alice hamesha jeetegi**, n odd ho to hamesha haregi (optimal play ke against)
- Kyunki: agar `n` even hai, `x=1` (jo hamesha valid divisor hai) choose karke `n` ko odd bana sakte ho, opponent ko odd number diya
- Odd numbers ke sirf odd divisors hote hain, isliye odd se subtract karne par hamesha even milta hai — is pattern se turns alternate hote hain aur even wala player hamesha jeetta hai
- Isliye simple formula: `return n % 2 == 0`

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
    bool divisorGame(int n) {
        return n % 2 == 0 ;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/divisor-game/)
