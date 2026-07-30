<div align="center">

# 3014. Minimum Number of Pushes to Type Word I

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Math-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Greedy_Distribution-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given word with distinct letters, remap keys 2-9 (8 keys) to letters optimally to minimize total pushes. Return minimum pushes needed.

---

## Examples

| Input | Output |
|-------|--------|
| "abcde" | 5 |
| "xycdefghij" | 12 |

---

## Approach - Greedy Distribution (8 keys, distinct letters)

word length = 10 (xycdefghij)

8 keys available. Distribute letters evenly:
First 8 letters → 1 push each (index 0-7)
Next 2 letters → 2 pushes each (index 8-9)

Total = 81 + 22 = 8+4 = 12 ✓


- Since letters ko **distinct** rehna hai aur sirf **8 keys** (2-9) available hain, har key pe multiple letters ja sakti hain lekin unka push count badhta jayega (1st letter=1 push, 2nd=2 pushes, etc.)
- Optimal strategy: letters ko **8 keys me evenly distribute** karo — pehle 8 letters ko 1-1 push do (unique keys), agle 8 ko 2-2 push do, aur so on
- Formula: index `i` (0-indexed) ke liye push count = `(i/8) + 1`
- Kyunki koi specific order matter nahi karta (sabhi letters equally weighted hain problem me), simple index-based calculation kaafi hai

---

## Complexity

| | |
|---|---|
| Time | O(1) since word.length <= 26 |
| Space | O(1) |

---

## Solution

```cpp
class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int totalPushes = 0;

        for (int i = 0; i < n; i++) {
            int pushCount = (i / 8) + 1;
            totalPushes += pushCount;
        }

        return totalPushes;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-i/)
