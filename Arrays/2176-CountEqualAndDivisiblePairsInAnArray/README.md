<div align="center">

# 2176. Count Equal and Divisible Pairs in an Array

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Arrays-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Brute_Force-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given array nums and integer k, return count of pairs (i,j) where i<j, nums[i]==nums[j], and (i*j) is divisible by k.

---

## Examples

| Input | Output |
|-------|--------|
| nums=[3,1,2,2,2,1,3], k=2 | 4 |
| nums=[1,2,3,4], k=1 | 0 |

---

## Approach - Brute Force Nested Loops

nums = [3,1,2,2,2,1,3] k=2

Check all pairs (i,j) where i<j:
(0,6): nums[0]=3==nums[6]=3, 06=0, 0%2==0 ✓ → count=1
(2,3): nums[2]=2==nums[3]=2, 23=6, 6%2==0 ✓ → count=2
(2,4): nums[2]=2==nums[4]=2, 24=8, 8%2==0 ✓ → count=3
(3,4): nums[3]=2==nums[4]=2, 34=12, 12%2==0 ✓ → count=4

Answer = 4 ✓


- Simple **nested loop** se sabhi pairs `(i,j)` check karo jahan `i<j`
- Do conditions check karo: `nums[i]==nums[j]` aur `(i*j) % k == 0`
- Dono conditions true hon to count badhao
- Constraints chote hain (`n<=100`) isliye O(n²) brute force acceptable hai

---

## Complexity

| | |
|---|---|
| Time | O(n²) |
| Space | O(1) |

---

## Solution

```cpp
class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int count = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] == nums[j] && (i * j) % k == 0) {
                    count++;
                }
            }
        }

        return count;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/count-equal-and-divisible-pairs-in-an-array/)
