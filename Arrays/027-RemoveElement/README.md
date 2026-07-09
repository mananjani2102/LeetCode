<div align="center">

# 27. Remove Element

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Arrays-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Two_Pointers-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given array nums and integer val, remove all occurrences of val in-place. Return k (count of remaining elements not equal to val).

---

## Examples

| Input | Output |
|-------|--------|
| nums=[3,2,2,3], val=3 | k=2, nums=[2,2,_,_] |
| nums=[0,1,2,2,3,0,4,2], val=2 | k=5, nums=[0,1,4,0,3,_,_,_] |

---

## Approach - Two Pointers
nums = [3,2,2,3]   val = 3
k=0
i=0: nums[0]=3==val → skip
i=1: nums[1]=2!=val → nums[k]=2, k=1
i=2: nums[2]=2!=val → nums[k]=2, k=2
i=3: nums[3]=3==val → skip
Result: k=2, nums=[2,2,...] ✓

- `k` slow pointer hai jo next valid position track karta hai
- `i` fast pointer se har element check karo
- Agar current element `val` ke equal nahi hai to `nums[k]` me copy karo aur `k` badha do
- End me `k` return karo — wahi valid elements ka count hai

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
    int removeElement(vector<int>& nums, int val) {
        int k = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
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

[LeetCode Problem](https://leetcode.com/problems/remove-element/)
