<div align="center">

# 69. Sqrt(x)

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Math-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Binary_Search-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given non-negative integer x, return square root of x rounded down to nearest integer. Built-in exponent functions use nahi kar sakte.

---

## Examples

| Input | Output |
|-------|--------|
| 4 | 2 |
| 8 | 2 |

---

## Approach - Binary Search
x = 8
left=1, right=8
mid=4: 4*4=16 > 8 → right=3
left=1, right=3
mid=2: 2*2=4 <= 8 → ans=2, left=3
left=3, right=3
mid=3: 3*3=9 > 8 → right=2
left=3, right=2 → loop ends
Answer = 2 ✓

- **1 se x** ke range me binary search karo
- Har `mid` ke liye check karo `mid*mid <= x`
- Sahi hai to `ans = mid` update karo aur right side me search karo (bada answer dhundo)
- Warna left side me jao
- `long long` use karo overflow bachane ke liye

---

## Complexity

| | |
|---|---|
| Time | O(log x) |
| Space | O(1) |

---

## Solution

```cpp
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;

        long long left = 1, right = x;
        long long ans = 0;

        while (left <= right) {
            long long mid = left + (right - left) / 2;

            if (mid * mid <= x) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return (int)ans;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/sqrtx/)
