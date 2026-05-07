<div align="center">

# 4. Median of Two Sorted Arrays

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Arrays-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Binary_Search-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given two sorted arrays `nums1` and `nums2` of size `m` and `n`, return the **median** of the two sorted arrays. Time complexity must be `O(log(m+n))`.

---

## Examples

| Input | Output |
|-------|--------|
| nums1=[1,3], nums2=[2] | 2.00000 |
| nums1=[1,2], nums2=[3,4] | 2.50000 |

---

## Approach — Binary Search on Smaller Array
nums1 = [1, 3]   nums2 = [2]
Smaller array pe binary search karo (nums1)

partition1 aur partition2 aise choose karo

ki left side = right side elements (±1)
maxLeft1 <= minRight2  AND  maxLeft2 <= minRight1

→ Correct partition mil gaya
Total odd → max(maxLeft1, maxLeft2) = median

Total even → (max(left) + min(right)) / 2 = median

- Hamesha **chote array** pe binary search karo
- Partition aisa dhundo jahan left half = right half (ya ±1)
- Odd total → left ka max hi median
- Even total → left ka max + right ka min, divide by 2

---

## Complexity

| | |
|---|---|
| Time | O(log(min(m,n))) |
| Space | O(1) |

---

## Solution

```cpp
// LeetCode 4 - Median of Two Sorted Arrays
// Approach: Binary Search on smaller array
// Time: O(log(min(m,n))) | Space: O(1)

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();
        int low = 0, high = m;

        while (low <= high) {
            int partition1 = (low + high) / 2;
            int partition2 = (m + n + 1) / 2 - partition1;

            int maxLeft1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
            int minRight1 = (partition1 == m) ? INT_MAX : nums1[partition1];

            int maxLeft2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
            int minRight2 = (partition2 == n) ? INT_MAX : nums2[partition2];

            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                if ((m + n) % 2 == 0) {
                    return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
                } else {
                    return max(maxLeft1, maxLeft2);
                }
            } else if (maxLeft1 > minRight2) {
                high = partition1 - 1;
            } else {
                low = partition1 + 1;
            }
        }

        return 0.0;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/median-of-two-sorted-arrays/)