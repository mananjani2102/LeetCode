<div align="center">

# 35. Search Insert Position

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Arrays-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Binary_Search-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given a sorted array of distinct integers and target, return the index if found, otherwise return the index where it would be inserted. Must run in O(log n).

---

## Examples

| Input | Output |
|-------|--------|
| nums=[1,3,5,6], target=5 | 2 |
| nums=[1,3,5,6], target=2 | 1 |
| nums=[1,3,5,6], target=7 | 4 |

---

## Approach - Binary Search

Standard binary search apply karo. Agar mid ka element target ke equal hai to wahi index return karo. Agar mid ka element target se chota hai to right half me search karo (left = mid+1). Warna left half me search karo (right = mid-1). Loop khatam hone par left pointer hi wo position hai jaha target insert hoga (na milne par).

---

## Complexity

| | |
|---|---|
| Time | O(log n) |
| Space | O(1) |

---

## Solution

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return left;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/search-insert-position/)
