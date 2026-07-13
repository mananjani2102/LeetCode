<div align="center">

# 33. Search in Rotated Sorted Array

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Arrays-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Modified_Binary_Search-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given rotated sorted array nums and target, find target's index in O(log n) time. Return -1 if not found.

---

## Examples

| Input | Output |
|-------|--------|
| nums=[4,5,6,7,0,1,2], target=0 | 4 |
| nums=[4,5,6,7,0,1,2], target=3 | -1 |
| nums=[1], target=0 | -1 |

---

## Approach - Modified Binary Search
nums = [4,5,6,7,0,1,2]   target=0
left=0,right=6, mid=3(val=7)
nums[left]=4 <= nums[mid]=7 → left half sorted
target(0) not in [4,7) range → search right half → left=4
left=4,right=6, mid=5(val=1)
nums[left]=0 <= nums[mid]=1 → left half sorted
target(0) in [0,1) range → search left half → right=4
left=4,right=4, mid=4(val=0)
nums[mid]==target → return 4 ✓

- Rotated array me kam se kam ek half hamesha **properly sorted** hota hai
- Check karo `nums[left] <= nums[mid]` — agar true to left half sorted hai
- Sorted half me target hai ya nahi check karo range se, phir usi half me search continue karo
- Warna doosre (unsorted lekin abhi bhi rotated-sorted) half me jao
- Standard binary search jaisa hi lekin har step pe extra check ke saath

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
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) return mid;

            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        return -1;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/search-in-rotated-sorted-array/)
