<div align="center">

# 896. Monotonic Array

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Arrays-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Two_Flags-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given integer array nums, return true if it is monotonic (either entirely non-increasing or non-decreasing).

---

## Examples

| Input | Output |
|-------|--------|
| [1,2,2,3] | true |
| [6,5,4,4] | true |
| [1,3,2] | false |

---

## Approach - Single Pass with Two Flags

nums = [1,3,2]

increasing=true, decreasing=true

i=1: nums[1]=3 > nums[0]=1 → decreasing=false
i=2: nums[2]=2 < nums[1]=3 → increasing=false

Both false → return false ✓


- Do boolean flags rakho: `increasing` aur `decreasing`, dono `true` se start karo
- Har adjacent pair check karo — agar `nums[i] > nums[i-1]` to `decreasing=false`, agar `nums[i] < nums[i-1]` to `increasing=false`
- Single pass ke baad, agar `increasing` ya `decreasing` me se koi ek bhi `true` bacha to array monotonic hai

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
    bool isMonotonic(vector<int>& nums) {
        bool increasing = true;
        bool decreasing = true;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                decreasing = false;
            }
            if (nums[i] < nums[i - 1]) {
                increasing = false;
            }
        }

        return increasing || decreasing;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/monotonic-array/)
