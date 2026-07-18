<div align="center">

# 70. Climbing Stairs

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Dynamic_Programming-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Fibonacci_Pattern-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given n steps to climb, where each move can be 1 or 2 steps, return number of distinct ways to reach the top.

---

## Examples

| Input | Output |
|-------|--------|
| 2 | 2 |
| 3 | 3 |

---

## Approach - Fibonacci Pattern

n=5

ways(1)=1, ways(2)=2
ways(3)=ways(2)+ways(1)=2+1=3
ways(4)=ways(3)+ways(2)=3+2=5
ways(5)=ways(4)+ways(3)=5+3=8

Answer = 8


- Har step pe pahunchne ke liye do options hain: **1 step pehle se** ya **2 steps pehle se** aana
- Isliye `ways(n) = ways(n-1) + ways(n-2)` — bilkul **Fibonacci sequence** jaisa
- `a, b` variables se **space optimize** karo (O(1) space, poora DP array banane ki zaroorat nahi)
- Har iteration me `a, b` ko aage shift karte raho

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
    int climbStairs(int n) {
        if (n <= 2) return n;

        int a = 1, b = 2;

        for (int i = 3; i <= n; i++) {
            int c = a + b;
            a = b;
            b = c;
        }

        return b;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/climbing-stairs/)
