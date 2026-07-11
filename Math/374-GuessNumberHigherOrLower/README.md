<div align="center">

# 374. Guess Number Higher or Lower

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Math-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Binary_Search-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Guess a picked number between 1 and n using guess() API, which tells if your guess is higher, lower, or equal to the picked number.

---

## Examples

| Input | Output |
|-------|--------|
| n=10, pick=6 | 6 |
| n=1, pick=1 | 1 |
| n=2, pick=1 | 1 |

---

## Approach - Binary Search
n=10, pick=6
left=1, right=10
mid=5: guess(5)=1 (too low) → left=6
left=6, right=10
mid=8: guess(8)=-1 (too high) → right=7
left=6, right=7
mid=6: guess(6)=0 (correct!) → return 6 ✓

- Standard **binary search** apply karo range [1, n] pe
- `guess(mid)` call karo — `0` mile to answer mil gaya
- `-1` mile (guess bada hai) to right half me search karo
- `1` mile (guess chota hai) to left half me search karo

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
    int guessNumber(int n) {
        int left = 1, right = n;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int result = guess(mid);

            if (result == 0) {
                return mid;
            }
            else if (result == -1) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return -1;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/guess-number-higher-or-lower/)
