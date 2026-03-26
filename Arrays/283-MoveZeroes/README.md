<div align="center">

# 283. Move Zeroes

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Arrays-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Two_Pointers-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given an array `nums`, move all `0`s to the end while maintaining the **relative order** of non-zero elements. Must be done **in-place**.

---

## Examples

| Input | Output |
|-------|--------|
| nums = [0,1,0,3,12] | [1,3,12,0,0] |
| nums = [0] | [0] |

---

## Approach — Two Pointers
```
nums = [0, 1, 0, 3, 12]

j=0 (slow pointer)
i=0 → 0 skip
i=1 → nums[j]=1, j=1
i=2 → 0 skip
i=3 → nums[j]=3, j=2
i=4 → nums[j]=12, j=3

Fill rest with 0 → [1, 3, 12, 0, 0] ✓
```

- `j` slow pointer — non-zero elements yahan rakhte hain
- `i` fast pointer — array traverse karta hai
- End me bacha hua fill karo `0` se

---

## Complexity

| | |
|---|---|
| Time | O(n) |
| Space | O(1) |

---

## Solution
```cpp
// LeetCode 283 - Move Zeroes
// Approach: Two Pointers
// Time: O(n) | Space: O(1)

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[j] = nums[i];
                j++;
            }
        }
        while (j < nums.size()) {
            nums[j] = 0;
            j++;
        }
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/move-zeroes/)
