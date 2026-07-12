<div align="center">

# 405. Convert a Number to Hexadecimal

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Bit_Manipulation-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Bit_Masking-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given 32-bit integer num, return its hexadecimal string representation. Negative numbers use two's complement. No built-in library functions allowed.

---

## Examples

| Input | Output |
|-------|--------|
| 26 | "1a" |
| -1 | "ffffffff" |

---

## Approach - Bit Masking (4 bits at a time)
num = 26 (binary: 11010)
n = 26
n & 15 = 26 & 1111 = 1010 = 10 → 'a', result="a"
n >>= 4 → n = 1
n & 15 = 1 & 1111 = 1 → '1', result="a1"
n >>= 4 → n = 0
Loop ends
reverse("a1") → "1a" ✓

- Number ko `unsigned int` me cast karo — isse **negative numbers automatically two's complement** representation le lete hain
- Har step pe `n & 15` (yani `& 0xF`) se **last 4 bits** (ek hex digit) nikalo
- `hexDigits` string se corresponding character lo
- `n >>= 4` se agle 4 bits ke liye shift karo
- End me result reverse karo (digits ulte order me bane the)

---

## Complexity

| | |
|---|---|
| Time | O(1) — max 8 iterations for 32-bit int |
| Space | O(1) |

---

## Solution

```cpp
class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";

        string hexDigits = "0123456789abcdef";
        string result = "";

        unsigned int n = (unsigned int)num;

        while (n != 0) {
            int digit = n & 15;
            result += hexDigits[digit];
            n >>= 4;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/convert-a-number-to-hexadecimal/)
