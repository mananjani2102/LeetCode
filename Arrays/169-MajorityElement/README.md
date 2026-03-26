<div align="center">

# 169. Majority Element

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Arrays-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Boyer_Moore-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given an array `nums` of size `n`, return the **majority element** that appears more than `n/2` times.

---

## Examples

| Input | Output |
|-------|--------|
| nums = [3,2,3] | 3 |
| nums = [2,2,1,1,1,2,2] | 2 |

---

## Approach — Boyer-Moore Voting Algorithm
```
nums = [2, 2, 1, 1, 1, 2, 2]

candidate=2, count=1
candidate=2, count=2
candidate=2, count=1  (1 ne ghata)
candidate=2, count=0
candidate=1, count=1  (naya candidate)
candidate=1, count=0
candidate=2, count=1  ✓ → return 2
```

- Candidate aur count track karo
- Count 0 ho to naya candidate lo
- Majority element hamesha bachega

---

## Complexity

| | |
|---|---|
| Time | O(n) |
| Space | O(1) |

---

## Solution
```cpp
// LeetCode 169 - Majority Element
// Approach: Boyer-Moore Voting Algorithm
// Time: O(n) | Space: O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;
        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }
        return candidate;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/majority-element/)
