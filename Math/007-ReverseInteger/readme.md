<div align="center">

# 7. Reverse Integer

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Math-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Pop_and_Push-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given a signed 32-bit integer `x`, return `x` with its digits **reversed**. If result is outside `[-2³¹, 2³¹-1]` range, return `0`.

---

## Examples

| Input | Output |
|-------|--------|
| x = 123 | 321 |
| x = -123 | -321 |
| x = 120 | 21 |

---

## Approach — Pop and Push
```
x = 123

digit = 3 → result = 3,   x = 12
digit = 2 → result = 32,  x = 1
digit = 1 → result = 321, x = 0

return 321 ✓
```

- Har digit `% 10` se pop karo
- Result me `* 10 +` karke push karo
- Overflow check karo `INT_MAX / 10` se

---

## Complexity

| | |
|---|---|
| Time | O(log n) |
| Space | O(1) |

---

## Solution
```cpp
// LeetCode 7 - Reverse Integer
// Approach: Pop and Push Digits
// Time: O(log n) | Space: O(1)

class Solution {
public:
    int reverse(int x) {
        int result = 0;
        while (x != 0) {
            int digit = x % 10;
            x /= 10;
            if (result > INT_MAX / 10 || result < INT_MIN / 10)
                return 0;
            result = result * 10 + digit;
        }
        return result;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/reverse-integer/)
