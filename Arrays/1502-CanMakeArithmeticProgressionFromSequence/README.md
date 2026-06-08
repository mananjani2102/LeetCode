<div align="center">

# 1502. Can Make Arithmetic Progression From Sequence

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Arrays-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Sort_and_Check-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given array arr, return true if it can be rearranged to form an arithmetic progression (same difference between consecutive elements).

---

## Examples

| Input | Output |
|-------|--------|
| [3,5,1] | true |
| [1,2,4] | false |

---

## Approach - Sort and Check

Array ko sort kar do. Sort hone ke baad agar arithmetic progression possible hai to consecutive elements ka difference hamesha same rahega. Pehla difference nikal lo (arr[1]-arr[0]), fir baaki sab consecutive pairs check karo - agar koi bhi pair ka difference is value se match nahi karta to false return karo.

---

## Complexity

| | |
|---|---|
| Time | O(n log n) - sorting ke liye |
| Space | O(1) |

---

## Solution

```cpp
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int diff = arr[1] - arr[0];

        for (int i = 2; i < arr.size(); i++) {
            if (arr[i] - arr[i - 1] != diff) {
                return false;
            }
        }

        return true;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/)
