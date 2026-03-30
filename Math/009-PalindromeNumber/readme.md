<div align="center">

# 9. Palindrome Number

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Math-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Reverse_Number-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given an integer `x`, return `true` if `x` is a **palindrome**, `false` otherwise.

---

## Examples

| Input | Output | Reason |
|-------|--------|--------|
| x = 121 | true | 121 = 121 ulta bhi |
| x = -121 | false | Negative = palindrome nahi |
| x = 10 | false | Ulta = 01 ≠ 10 |

---

## Approach — Reverse the Number
```
x = 121

original = 121
digit = 1  → revers = 1,   x = 12
digit = 2  → revers = 12,  x = 1
digit = 1  → revers = 121, x = 0

original == revers → 121 == 121 ✓ → true
```

- Negative numbers → seedha `false`
- Number ko reverse karo
- Original == Reversed → palindrome

---

## Complexity

| | |
|---|---|
| Time | O(log n) |
| Space | O(1) |

---

## Solution
```cpp
// LeetCode 9 - Palindrome Number
// Approach: Reverse the Number
// Time: O(log n) | Space: O(1)

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        long long revers = 0;
        int original = x;
        while (x != 0) {
            int digit = x % 10;
            revers = revers * 10 + digit;
            x = x / 10;
        }
        return original == revers;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/palindrome-number/)
