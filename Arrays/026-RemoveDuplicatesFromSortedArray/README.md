<div align="center">

# 26. Remove Duplicates from Sorted Array

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Arrays-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Two_Pointers-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given a sorted array nums, remove duplicates in-place so each unique element appears only once. Return k (count of unique elements).

---

## Examples

| Input | Output |
|-------|--------|
| [1,1,2] | k=2, nums=[1,2,_] |
| [0,0,1,1,1,2,2,3,3,4] | k=5, nums=[0,1,2,3,4,_,_,_,_,_] |

---

## Approach - Two Pointers
nums = [0,0,1,1,1,2,2,3,3,4]
k=1 (slow pointer)

i=1: nums[1]=0 == nums[0]=0 → skip

i=2: nums[2]=1 != nums[1]=0 → nums[k]=1, k=2

i=3: nums[3]=1 == nums[2]=1 → skip

i=4: nums[4]=1 == nums[3]=1 → skip

i=5: nums[5]=2 != nums[4]=1 → nums[k]=2, k=3

...

Result: k=5, nums=[0,1,2,3,4,...] ✓

- `k` slow pointer hai jo next unique element ki position track karta hai
- `i` fast pointer se har element check karo
- Agar current element previous se alag hai to `nums[k]` me copy karo aur `k` badha do
- End me `k` return karo

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
    int removeDuplicates(vector<int>& nums) {
        int k = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                nums[k] = nums[i];
                k++;
            }
        }

        return k;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)
