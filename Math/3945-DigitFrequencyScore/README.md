<div align="center">

# 3945. Digit Frequency Score

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Math-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Digit_Extraction-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given integer n, score is the sum of d * freq(d) for all distinct digits d, where freq(d) is how many times digit d appears in n.

---

## Examples

| Input | Output |
|-------|--------|
| 122 | 5 |
| 101 | 2 |

---

## Approach - Digit Extraction + Sum

Score formula d * freq(d) sum over distinct digits asal me sirf sabhi digits ka simple sum hota hai - kyunki har baar jab digit d occur karta hai, wo apni value d contribute karta hai. Isliye humein sirf number ke har digit ko nikal kar (n % 10 se) sum karna hai, har baar n ko 10 se divide karte hue.

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
    int digitFrequencyScore(int n) {
         int sum =0;

         while(n){
                sum +=  n%10;
                n = n/10;
         }

         return sum;

    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/digit-frequency-score/)
