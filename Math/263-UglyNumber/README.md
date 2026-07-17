<div align="center">

# 263. Ugly Number

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Math-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Divide_by_2_3_5-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given integer n, return true if it is an ugly number (only has prime factors 2, 3, and 5).

---

## Examples

| Input | Output |
|-------|--------|
| 6 | true |
| 1 | true |
| 14 | false |

---

## Approach - Divide by 2, 3, 5

```
n = 6

n%2==0 → n=3
n%3==0 → n=1

n==1 → true (koi aur prime factor nahi bacha) ✓
```
n = 14
n%2==0 → n=7
n%3!=0, n%5!=0 → loops end
n!=1 → false (7 bach gaya, jo prime hai lekin 2,3,5 nahi) ✗

- `n <= 0` ko pehle hi `false` handle karo
- Jab tak `n` ko **2, 3, ya 5** se divide kiya ja sake, karte raho
- End me agar `n == 1` bacha to sab prime factors 2, 3, 5 the → **ugly**
- Kuch aur bacha to koi doosra prime factor tha → **not ugly**

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
    bool isUgly(int n) {
        if (n <= 0) return false;

        while (n % 2 == 0) n /= 2;
        while (n % 3 == 0) n /= 3;
        while (n % 5 == 0) n /= 5;

        return n == 1;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/ugly-number/)
