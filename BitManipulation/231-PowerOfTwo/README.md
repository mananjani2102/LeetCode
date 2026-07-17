<div align="center">

# 231. Power of Two

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Bit_Manipulation-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Bit_Trick-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given integer n, return true if it is a power of two (n == 2^x for some integer x).

---

## Examples

| Input | Output |
|-------|--------|
| 1 | true |
| 16 | true |
| 3 | false |

---

## Approach - Bit Manipulation (n & (n-1))

```
n = 16 → binary: 10000
n-1 = 15 → binary: 01111

n & (n-1) = 10000 & 01111 = 00000 = 0
→ power of two ✓
```
n = 3 → binary: 011
n-1 = 2 → binary: 010
n & (n-1) = 011 & 010 = 010 = 2 (not 0)
→ not power of two ✗

- Power of 2 numbers ki binary me sirf **ek hi bit set** hoti hai (jaise 100, 1000)
- `n & (n-1)` us single set bit ko **hata deta hai**
- Agar result `0` hai to `n` power of 2 tha
- `n <= 0` ko pehle hi `false` handle karo

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
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        return (n & (n - 1)) == 0;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/power-of-two/)
