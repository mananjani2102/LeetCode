<div align="center">

# 258. Add Digits

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Math-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Digital_Root_Formula-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given integer num, repeatedly add its digits until result has only one digit. Return that digit.

---

## Examples

| Input | Output |
|-------|--------|
| 38 | 2 |
| 0 | 0 |

---

## Approach - Digital Root Formula (O(1))

```
num = 38

38 % 9 = 2 (since 38 = 4*9 + 2)

Verify: 3+8=11, 1+1=2 ✓ matches!
```
num = 9
9 % 9 = 0, lekin single digit result "9" hona chahiye, "0" nahi
Special case: agar num!=0 aur num%9==0 to answer 9 hai

- Ye "digital root" ka mathematical property hai — repeatedly digit sum karne se jo single digit milta hai, wo `num mod 9` ke barabar hota hai (with special case for multiples of 9)
- `num == 0` → answer `0`
- `num % 9 == 0` (aur num!=0) → answer `9`
- Warna answer `num % 9`
- Isse loop/recursion ki zaroorat nahi, O(1) me solve ho jata hai

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
    int addDigits(int num) {
        if (num == 0) return 0;
        if (num % 9 == 0) return 9;
        return num % 9;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/add-digits/)
