<div align="center">

# 1979. Find Greatest Common Divisor of Array

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Math-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Euclidean_Algorithm-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given integer array nums, return GCD of the smallest and largest number in nums.

---

## Examples

| Input | Output |
|-------|--------|
| [2,5,6,9,10] | 2 |
| [7,5,6,8,3] | 1 |
| [3,3] | 3 |

---

## Approach - Euclidean Algorithm on Min and Max

nums = [2,5,6,9,10]

smallest = min(nums) = 2
largest = max(nums) = 10

gcd(2, 10):
10 % 2 = 0 → gcd = 2

Answer = 2 ✓


- STL functions `min_element` aur `max_element` se array ka **smallest** aur **largest** value nikalo
- `__gcd()` built-in function use karo (C++ STL) jo **Euclidean algorithm** internally use karta hai
- Simple aur efficient one-liner solution

---

## Complexity

| | |
|---|---|
| Time | O(n + log(min(a,b))) |
| Space | O(1) |

---

## Solution

```cpp
class Solution {
public:
    int findGCD(vector<int>& nums) {

        int smallest = *min_element(nums.begin(), nums.end());
        int largest = *max_element(nums.begin(), nums.end());

        return __gcd(smallest, largest);
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/find-greatest-common-divisor-of-array/)
