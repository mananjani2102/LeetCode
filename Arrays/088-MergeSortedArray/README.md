<div align="center">

# 88. Merge Sorted Array

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Arrays-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Two_Pointers_From_Back-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given two sorted arrays nums1 (with extra space) and nums2, merge nums2 into nums1 in-place so nums1 becomes one sorted array.

---

## Examples

| Input | Output |
|-------|--------|
| nums1=[1,2,3,0,0,0], m=3, nums2=[2,5,6], n=3 | [1,2,2,3,5,6] |
| nums1=[1], m=1, nums2=[], n=0 | [1] |
| nums1=[0], m=0, nums2=[1], n=1 | [1] |

---

## Approach - Two Pointers From Back
nums1 = [1,2,3,0,0,0]   nums2 = [2,5,6]
i=2(val=3), j=2(val=6), k=5
6>3 → nums1[5]=6, j=1, k=4
i=2(val=3), j=1(val=5), k=4
5>3 → nums1[4]=5, j=0, k=3
i=2(val=3), j=0(val=2), k=3
3>2 → nums1[3]=3, i=1, k=2
i=1(val=2), j=0(val=2), k=2
2<=2 → nums1[2]=2, j=-1, k=1
j<0 loop khatam, nums1 unchanged front part
Result: [1,2,2,3,5,6] ✓

- End se start karo — `nums1` ke actual elements (`i`) aur `nums2` (`j`) dono ko peeche se compare karo
- **Bada element** end me (`k` position) rakho
- `nums2` khatam nahi hua to bache hue elements copy kar do
- `nums1` khud khali jagah use karta hai, extra space nahi chahiye

---

## Complexity

| | |
|---|---|
| Time | O(m + n) |
| Space | O(1) |

---

## Solution

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }

        while (j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/merge-sorted-array/)
