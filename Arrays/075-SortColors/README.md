<div align="center">

# 75. Sort Colors

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Arrays-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Dutch_National_Flag-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given array nums with values 0,1,2 (red,white,blue), sort in-place so same colors are adjacent in order 0,1,2. No library sort allowed. Follow up: one-pass, O(1) space.

---

## Examples

| Input | Output |
|-------|--------|
| [2,0,2,1,1,0] | [0,0,1,1,2,2] |
| [2,0,1] | [0,1,2] |

---

## Approach - Dutch National Flag Algorithm (One Pass, Three Pointers)

nums = [2,0,2,1,1,0]

low=0,mid=0,high=5

mid=0: nums[0]=2 → swap(0,5) → [0,0,2,1,1,2], high=4
mid=0: nums[0]=0 → swap(0,0), low=1,mid=1
mid=1: nums[1]=0 → swap(1,1), low=2,mid=2
mid=2: nums[2]=2 → swap(2,4) → [0,0,1,1,2,2], high=3
mid=2: nums[2]=1 → mid=3
mid=3: nums[3]=1 → mid=4

mid(4)>high(3) → loop ends

Result: [0,0,1,1,2,2] ✓


- **Three pointers**: `low` (0s ki boundary), `mid` (current element), `high` (2s ki boundary)
- `nums[mid]==0` → `low` ke sath swap karo, dono `low` aur `mid` badhao
- `nums[mid]==1` → sirf `mid` badhao (already sahi jagah hai)
- `nums[mid]==2` → `high` ke sath swap karo, sirf `high` ghatao (`mid` nahi badhta kyunki naya swapped element check karna hai)
- Ye **single pass** me O(1) space me poora sort ho jata hai — follow-up requirement satisfy hoti hai

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
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1) {
                mid++;
            }
            else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/sort-colors/)
