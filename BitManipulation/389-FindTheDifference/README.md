<div align="center">

# 389. Find the Difference

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Bit_Manipulation-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-XOR_Trick-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given strings s and t where t is s shuffled plus one extra letter, return the extra letter that was added.

---

## Examples

| Input | Output |
|-------|--------|
| s="abcd", t="abcde" | "e" |
| s="", t="y" | "y" |

---

## Approach - XOR Trick

s = "abcd" t = "abcde"

XOR all characters of s: a^b^c^d
XOR all characters of t: a^b^c^d^e

Combined XOR: (a^b^c^d) ^ (a^b^c^d^e)
= a^a ^ b^b ^ c^c ^ d^d ^ e
= 0^0^0^0^e = e ✓


- **XOR ki property**: `x^x = 0` aur `x^0 = x`
- Agar `s` ke sabhi characters aur `t` ke sabhi characters ko ek sath XOR karo, to **common characters cancel out** ho jayenge (kyunki wo pairs me hain)
- Sirf wo character bachega jo sirf `t` me extra hai — wahi answer hai
- Bahut **elegant O(1) space** solution hai, HashMap ki zaroorat nahi

---

## Complexity

| | |
|---|---|
| Time | O(n) |
| Space | O(1) |

---

## Solution

```cpp
class Solution {
public:
    char findTheDifference(string s, string t) {
        char result = 0;

        for (char ch : s) {
            result ^= ch;
        }

        for (char ch : t) {
            result ^= ch;
        }

        return result;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/find-the-difference/)
