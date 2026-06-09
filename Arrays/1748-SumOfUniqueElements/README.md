<div align="center">

# 1748. Sum of Unique Elements

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Arrays-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Frequency_Array-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given integer array nums, return the sum of all unique elements (elements that appear exactly once).

---

## Examples

| Input | Output |
|-------|--------|
| [1,2,3,2] | 4 |
| [1,1,1,1,1] | 0 |
| [1,2,3,4,5] | 15 |

---

## Approach - Frequency Array

Values 1-100 ke range me hain, isliye frequency array banao. Har number ka count store karo. Fir 1 se 100 tak loop chalao, jis number ka frequency exactly 1 ho usko sum me add kar do.

---

## Complexity

| | |
|---|---|
| Time | O(n) |
| Space | O(1) fixed 101 size array |

---

## Solution

```cpp
class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        vector<int> freq(101, 0);

        for (int num : nums) {
            freq[num]++;
        }

        int sum = 0;

        for (int i = 1; i <= 100; i++) {
            if (freq[i] == 1) {
                sum += i;
            }
        }

        return sum;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/sum-of-unique-elements/)
