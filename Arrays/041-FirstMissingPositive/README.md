<div align="center">

# 41. First Missing Positive

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Arrays-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Cyclic_Sort-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given unsorted integer array nums, return the smallest positive integer not present in nums. Must run in O(n) time and O(1) auxiliary space.

---

## Examples

| Input | Output |
|-------|--------|
| [1,2,0] | 3 |
| [3,4,-1,1] | 2 |
| [7,8,9,11,12] | 1 |

---

## Approach - Cyclic Sort
nums = [3,4,-1,1]
i=0: nums[0]=3 → should be at index 2
swap(nums[0], nums[2]) → [-1,4,3,1]
nums[0]=-1 → invalid (negative), stop
i=1: nums[1]=4 → should be at index 3
swap(nums[1], nums[3]) → [-1,1,3,4]
nums[1]=1 → should be at index 0
swap(nums[1], nums[0]) → [1,-1,3,4]
nums[1]=-1 → invalid, stop
i=2: nums[2]=3 → already at correct index (index 2 = value 3)
i=3: nums[3]=4 → already at correct index
Array now: [1,-1,3,4]
Check: index0=1✓, index1=-1≠2 → return 2 ✓

- **Cyclic sort**: har positive number `x` (jahan `1<=x<=n`) ko uske sahi position `x-1` pe rakhne ki koshish karo
- `nums[i]` valid range me hai aur galat position pe hai to **swap** karo
- Dusre pass me check karo — jo pehla index apni sahi value (`i+1`) nahi rakhta, wahi answer hai
- Sab correct hon to `n+1` return karo

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
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        return n + 1;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/first-missing-positive/)
