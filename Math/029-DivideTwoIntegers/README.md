<div align="center">

# 29. Divide Two Integers

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Math-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Bit_Shifting-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given dividend and divisor, divide without using multiplication, division, or mod operators. Truncate toward zero. Clamp result to 32-bit signed integer range.

---

## Examples

| Input | Output |
|-------|--------|
| dividend=10, divisor=3 | 3 |
| dividend=7, divisor=-3 | -2 |

---

## Approach - Bit Shifting (Repeated Doubling)
dividend=10, divisor=3
dvd=10, dvs=3
Outer loop (dvd>=dvs):
temp=3, multiple=1
Inner: dvd(10)>=temp<<1(6) → temp=6, multiple=2
Inner: dvd(10)>=temp<<1(12)? No → stop inner
dvd -= temp(6) → dvd=4
result += multiple(2) → result=2
Outer loop (dvd(4)>=dvs(3)):
temp=3, multiple=1
Inner: dvd(4)>=temp<<1(6)? No → stop inner
dvd -= temp(3) → dvd=1
result += multiple(1) → result=3
dvd(1) < dvs(3) → loop ends
result = 3 ✓

- Multiplication/division use kiye bina, **bit shifting** (`<<`) se divisor ko double karte raho jab tak wo dividend se bada na ho jaye
- Har baar bada doubled chunk subtract karo aur uska corresponding multiple result me add karo
- Ye approach O(log²n) me kaam karta hai — normal repeated subtraction se kaafi fast
- Sign handle karo alag se, aur `INT_MIN / -1` overflow case ko special handle karo

---

## Complexity

| | |
|---|---|
| Time | O(log²n) |
| Space | O(1) |

---

## Solution

```cpp
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;

        long long dvd = abs((long long)dividend);
        long long dvs = abs((long long)divisor);
        long long result = 0;

        while (dvd >= dvs) {
            long long temp = dvs;
            long long multiple = 1;

            while (dvd >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }

            dvd -= temp;
            result += multiple;
        }

        bool negative = (dividend < 0) != (divisor < 0);
        return negative ? -(int)result : (int)result;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/divide-two-integers/)
