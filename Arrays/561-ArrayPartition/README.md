<div align="center">

# 561. Array Partition

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Arrays-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Sort_and_Pair-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given 2n integers, group them into n pairs such that sum of min(ai,bi) for all pairs is maximized. Return the maximized sum.

---

## Examples

| Input | Output |
|-------|--------|
| [1,4,3,2] | 4 |
| [6,2,6,5,1,2] | 9 |

---

## Approach - Sort and Pair
nums = [1,4,3,2]
Sort → [1,2,3,4]
Pair adjacent: (1,2) and (3,4)
min(1,2)=1, min(3,4)=3
Sum = 1+3 = 4 ✓

- Array ko **sort** kar do
- Adjacent elements ko pair banao — `(nums[0],nums[1]), (nums[2],nums[3])...`
- Sorted array me pair ka **smaller element** hamesha **even index** pe hota hai
- Isliye har even index (`0, 2, 4...`) ka element sum me add karo
- Ye greedy approach isliye kaam karta hai kyunki sorted array me adjacent pairing waste minimize karta hai

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
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int sum = 0;
        for (int i = 0; i < nums.size(); i += 2) {
            sum += nums[i];
        }

        return sum;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/array-partition/)
