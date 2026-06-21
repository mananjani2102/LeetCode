<div align="center">

# 31. Next Permutation

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Arrays-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Find_Pivot_Swap_Reverse-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given array nums, find the next lexicographically greater permutation in-place. If not possible, rearrange to lowest order (ascending).

---

## Examples

| Input | Output |
|-------|--------|
| [1,2,3] | [1,3,2] |
| [3,2,1] | [1,2,3] |
| [1,1,5] | [1,5,1] |

---

## Approach - Find Pivot + Swap + Reverse
nums = [1,2,3]
Step 1 - Right se pivot dhundo (pehla element jo chota ho next se):

i=1: nums[1]=2 < nums[2]=3 → pivot=1
Step 2 - Pivot se bada smallest element dhundo right me:

i=2: nums[2]=3 > nums[1]=2 → swap → [1,3,2]
Step 3 - pivot+1 se end tak reverse karo:

Already sorted → [1,3,2] ✓

- Right se pehla **pivot** dhundo jahan `nums[i] < nums[i+1]`
- Pivot nahi mila to poora array **reverse** kar do (descending tha)
- Pivot mila to right side me pivot se bada **smallest element** dhundo aur swap karo
- Pivot ke baad wala hissa **reverse** kar do

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
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pivot = -1;

        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                pivot = i;
                break;
            }
        }

        if (pivot == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        for (int i = n - 1; i > pivot; i--) {
            if (nums[i] > nums[pivot]) {
                swap(nums[i], nums[pivot]);
                break;
            }
        }

        reverse(nums.begin() + pivot + 1, nums.end());
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/next-permutation/)
