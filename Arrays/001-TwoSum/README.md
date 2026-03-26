<div align="center">

# 1. Two Sum

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Arrays-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Brute_Force-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given an array of integers `nums` and an integer `target`, return **indices** of the two numbers such that they add up to `target`.

---

## Examples

| Input | Output |
|-------|--------|
| nums = [2,7,11,15], target = 9 | [0,1] |
| nums = [3,2,4], target = 6 | [1,2] |
| nums = [3,3], target = 6 | [0,1] |

---

## Approach — Brute Force
```
nums = [2, 7, 11, 15]   target = 9

i=0, j=1 → 2 + 7  = 9  ✓ → return [0, 1]
```

- Har ek pair `(i, j)` check karo
- Agar `nums[i] + nums[j] == target` → return karo

---

## Complexity

| | |
|---|---|
| Time | O(n²) |
| Space | O(1) |

---

## Solution
```cpp
// LeetCode 1 - Two Sum
// Approach: Brute Force
// Time: O(n²) | Space: O(1)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                if(nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/two-sum/)
