<div align="center">

# 350. Intersection of Two Arrays II

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Arrays-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-HashMap_Frequency-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given two integer arrays nums1 and nums2, return their intersection where each element appears as many times as it shows in both arrays.

---

## Examples

| Input | Output |
|-------|--------|
| nums1=[1,2,2,1], nums2=[2,2] | [2,2] |
| nums1=[4,9,5], nums2=[9,4,9,8,4] | [4,9] |

---

## Approach - HashMap Frequency Count

nums1 = [1,2,2,1] nums2 = [2,2]

freq (from nums1): 1:2, 2:2

Check nums2:
2: freq[2]=2>0 → add 2, freq[2]=1
2: freq[2]=1>0 → add 2, freq[2]=0

Result = [2,2] ✓


- `nums1` ke har number ka **frequency** count karo HashMap me
- `nums2` traverse karo — agar us number ka count `freq` me `>0` hai to result me add karo aur **frequency decrement** karo (taaki repeated matches na ho excess me)
- Ye approach har element ko **exact frequency** ke hisab se match karta hai

**Follow-up Answers:**
1. **Sorted arrays**: Two pointers technique use karo — O(n+m) time, O(1) extra space (excluding output), no HashMap chahiye
2. **nums1 chota hai**: HashMap `nums1` (chote array) pe banao — memory kam lagegi
3. **nums2 disk pe hai**: Chunks me `nums2` ko load karo, `nums1` ka HashMap memory me rakho, har chunk ko process karke result accumulate karo — external sorting/merging techniques bhi use ho sakte hain agar dono disk pe hon

---

## Complexity

| | |
|---|---|
| Time | O(n + m) |
| Space | O(min(n, m)) |

---

## Solution

```cpp
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> freq;

        for (int num : nums1) {
            freq[num]++;
        }

        vector<int> result;

        for (int num : nums2) {
            if (freq[num] > 0) {
                result.push_back(num);
                freq[num]--;
            }
        }

        return result;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/intersection-of-two-arrays-ii/)
