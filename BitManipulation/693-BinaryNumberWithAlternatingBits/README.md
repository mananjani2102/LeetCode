<div align="center">

# 693. Binary Number with Alternating Bits

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Bit_Manipulation-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Bit_Shifting-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Ek positive integer `n` diya hai — check karo ki uske binary bits **alternating** hain ya nahi.  
Matlab har do adjacent bits alag honi chahiye.

---

## Examples

| Input | Binary | Output | Reason |
|-------|--------|--------|--------|
| 5  | `101`  | `true`  | 1→0→1 alternating ✓ |
| 7  | `111`  | `false` | 1→1 same ✗ |
| 11 | `1011` | `false` | 1→1 same ✗ |
| 10 | `1010` | `true`  | 1→0→1→0 alternating ✓ |

---

## Approach — Bit Shifting

```
n = 5 → binary: 101

Step 1: prev = 5 & 1 = 1,  n = 5 >> 1 = 2  (10)
Step 2: cur  = 2 & 1 = 0,  cur != prev ✓,  prev=0, n = 2>>1 = 1  (1)
Step 3: cur  = 1 & 1 = 1,  cur != prev ✓,  prev=1, n = 1>>1 = 0
Step 4: n == 0 → loop khatam

return true ✓
```

- `n & 1` se last bit nikalo
- `n >> 1` se ek bit right shift karo
- Agar current bit == previous bit → `false` return karo
- Poora loop bina mismatch ke gaya → `true`

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
    bool hasAlternatingBits(int n) {
        int prev = n & 1;
        n = n >> 1;

        while (n > 0) {
            int cur = n & 1;
            if (cur == prev) return false;
            prev = cur;
            n = n >> 1;
        }

        return true;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/binary-number-with-alternating-bits/)