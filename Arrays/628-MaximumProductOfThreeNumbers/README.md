<div align="center">

# 628. Maximum Product of Three Numbers

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Arrays-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Sort_Compare_Cases-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given integer array nums, find three numbers whose product is maximum and return that product.

---

## Examples

| Input | Output |
|-------|--------|
| [1,2,3] | 6 |
| [1,2,3,4] | 24 |
| [-1,-2,-3] | -6 |

---

## Approach - Sort Compare Cases
nums = [-4,-3,1,2,3]
Sort → [-4,-3,1,2,3]
Case 1 - Top 3 largest:
123 = 6
Case 2 - Two smallest (negatives) * largest:
(-4)*(-3)*3 = 36
Max = 36 ✓ (do negatives multiply karke positive banate hain)

- Array ko **sort** kar do
- Do possible cases check karo:
  1. **Top 3 largest** numbers ka product (`nums[n-1]*nums[n-2]*nums[n-3]`)
  2. **Do sabse chote** (jo negative ho sakte hain) × **sabse bada** number (`nums[0]*nums[1]*nums[n-1]`)
- Dono me se jo **max** ho wahi answer hai
- Negative × negative = positive, isliye do bade negatives max product de sakte hain

---

## Complexity

| | |
|---|---|
| Time | O(n log n) |
| Space | O(1) |

---

## Solution

```cpp
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int product1 = nums[n - 1] * nums[n - 2] * nums[n - 3];
        int product2 = nums[0] * nums[1] * nums[n - 1];

        return max(product1, product2);
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/maximum-product-of-three-numbers/)
