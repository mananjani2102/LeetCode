<div align="center">

# 349. Intersection of Two Arrays

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Arrays-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-HashSet-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given two integer arrays nums1 and nums2, return array of their intersection. Result must have unique elements, any order.

---

## Examples

| Input | Output |
|-------|--------|
| nums1=[1,2,2,1], nums2=[2,2] | [2] |
| nums1=[4,9,5], nums2=[9,4,9,8,4] | [9,4] |

---

## Approach - HashSet
nums1 = [1,2,2,1]   nums2 = [2,2]
set1 = {1, 2}  (duplicates automatically removed)
Check nums2:
2 → present in set1 → result.insert(2)
2 → already in result → no change
result = {2} → [2] ✓

- `nums1` ko HashSet me daalo (duplicates automatically remove ho jate hain)
- `nums2` ke har element ke liye check karo `set1` me hai ya nahi
- Agar hai to result set me add karo (ye bhi duplicates avoid karta hai)
- End me result set ko vector me convert karke return karo

---

## Complexity

| | |
|---|---|
| Time | O(n + m) |
| Space | O(n + m) |

---

## Solution

```cpp
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> result;

        for (int num : nums2) {
            if (set1.count(num)) {
                result.insert(num);
            }
        }

        return vector<int>(result.begin(), result.end());
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/intersection-of-two-arrays/)
