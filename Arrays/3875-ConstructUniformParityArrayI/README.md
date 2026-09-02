<div align="center">

# 3875. Construct Uniform Parity Array I

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Arrays-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Brain_Teaser-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given array nums1 of n distinct integers, construct nums2 of same length where every element is either nums1[i] itself or nums1[i]-nums1[j] (j≠i), such that all elements of nums2 end up the same parity (all odd or all even). Return whether it's possible.

---

## Examples

| Input | Output |
|-------|--------|
| [2,3] | true |
| [4,6] | true |

---

## Approach - Brain Teaser (Parity Math)
Case A: nums1 = [4,6] → both already even
  set nums2[i] = nums1[i] for every i → [4,6], all even ✓

Case B: nums1 = [2,3] → mixed parity (2 even, 3 odd)
  for each i, pick nums2[i] = nums1[i] - nums1[j] where j has DIFFERENT parity than i
  even - odd = odd, odd - even = odd → every such difference is odd
  nums2[0] = 2-3 = -1 (odd), nums2[1] = 3-2 = 1 (odd) → all odd ✓

So in every possible case (all-even, all-odd, or mixed), a valid nums2 always exists.


- **Case 1 — nums1 saare same parity ke hai** (sab even ya sab odd): seedha `nums2[i] = nums1[i]` set kar do, condition already satisfy ho jaati hai
- **Case 2 — nums1 me mix hai** (odd aur even dono maujood): har index `i` ke liye ek aisa `j` chuno jiski parity `i` se **different** ho, aur `nums2[i] = nums1[i] - nums1[j]` set karo — kyunki **odd−even ya even−odd hamesha odd hota hai**, isse saare `nums2[i]` odd ban jaate hai (chahe khud `nums1[i]` odd ho ya even, use hamesha ek opposite-parity element se subtract kiya ja sakta hai kyunki mix case me dono types available hai)
- Isliye **teeno hi scenarios** (all-even, all-odd, ya mixed) me valid `nums2` bana sakte hai — matlab answer **hamesha `true`** hota hai, kisi bhi input ke liye
- Ye ek pure **math/brain-teaser** observation hai — koi loop ya extra data structure ki zarurat nahi, seedha `true` return kar do

---

## Complexity

| | |
|---|---|
| Time | O(1) |
| Space | O(1) |

---

## Solution

```cpp
class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        return true;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/construct-uniform-parity-array-i/)
