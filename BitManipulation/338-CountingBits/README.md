<div align="center">

# 338. Counting Bits

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Bit_Manipulation-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-DP_with_Bit_Trick-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given integer n, return array ans where ans[i] is the number of 1's in binary representation of i, for all 0<=i<=n. Solve in O(n) without built-in functions.

---

## Examples

| Input | Output |
|-------|--------|
| 2 | [0,1,1] |
| 5 | [0,1,1,2,1,2] |

---

## Approach - Dynamic Programming (i & (i-1))
i=1: 1 & 0 = 0 → ans[1] = ans[0]+1 = 0+1 = 1
i=2: 2 & 1 = 0 (10 & 01 = 00) → ans[2] = ans[0]+1 = 1
i=3: 3 & 2 = 2 (11 & 10 = 10) → ans[3] = ans[2]+1 = 2
i=4: 4 & 3 = 0 (100 & 011 = 000) → ans[4] = ans[0]+1 = 1
i=5: 5 & 4 = 4 (101 & 100 = 100) → ans[5] = ans[4]+1 = 2
Result: [0,1,1,2,1,2] ✓

- `i & (i-1)` trick **last set bit** ko remove karta hai number se
- Isliye `ans[i] = ans[i & (i-1)] + 1` — jo pehle se calculate ho chuka hai use karke O(1) me current answer nikal lo
- Ye **DP approach** hai jo previously computed values reuse karta hai
- Single pass me O(n) time me solve ho jata hai, built-in popcount function use kiye bina

---

## Complexity

| | |
|---|---|
| Time | O(n) |
| Space | O(1) extra (excluding output array) |

---

## Solution

```cpp
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            ans[i] = ans[i & (i - 1)] + 1;
        }

        return ans;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/counting-bits/)
