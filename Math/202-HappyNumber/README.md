<div align="center">

# 202. Happy Number

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Math-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-HashSet_Cycle_Detection-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given number n, repeatedly replace it with sum of squares of its digits. If it reaches 1, it's happy. If it loops endlessly without reaching 1, it's not happy.

---

## Examples

| Input | Output |
|-------|--------|
| 19 | true |
| 2 | false |

---

## Approach - HashSet Cycle Detection
n = 19
1²+9² = 1+81 = 82
8²+2² = 64+4 = 68
6²+8² = 36+64 = 100
1²+0²+0² = 1
Reached 1 → happy! true ✓

- Har number ke digits ka **square sum** nikalo (helper function `getNext`)
- HashSet me pehle se dekhe hue numbers store karo
- Agar number `1` ho jaye → **happy**
- Agar number pehle se seen hai (cycle detect) → **not happy**

---

## Complexity

| | |
|---|---|
| Time | O(log n) |
| Space | O(log n) |

---

## Solution

```cpp
class Solution {
public:
    int getNext(int n) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n = n / 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> seen;

        while (n != 1 && seen.find(n) == seen.end()) {
            seen.insert(n);
            n = getNext(n);
        }

        return n == 1;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/happy-number/)
