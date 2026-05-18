<div align="center">

# 53. Maximum Subarray

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Arrays-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Kadanes_Algorithm-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given an integer array `nums`, find the **subarray** with the largest sum, return its sum.

---

## Examples

| Input | Output |
|-------|--------|
| [-2,1,-3,4,-1,2,1,-5,4] | 6 |
| [1] | 1 |
| [5,4,-1,7,8] | 23 |

---

## Approach — Kadane's Algorithm
nums = [-2,1,-3,4,-1,2,1,-5,4]
i=0: currSum=-2, maxSum=-2

i=1: currSum=max(1,-2+1)=1,   maxSum=1

i=2: currSum=max(-3,1-3)=-2,  maxSum=1

i=3: currSum=max(4,-2+4)=4,   maxSum=4

i=4: currSum=max(-1,4-1)=3,   maxSum=4

i=5: currSum=max(2,3+2)=5,    maxSum=5

i=6: currSum=max(1,5+1)=6,    maxSum=6  ← best

i=7: currSum=max(-5,6-5)=1,   maxSum=6

i=8: currSum=max(4,1+4)=5,    maxSum=6
Answer = 6 ✓ ([4,-1,2,1])

- `currSum` track karo — current subarray ka sum
- Har step pe decide karo: naya start karo ya purane me add karo → `max(nums[i], currSum+nums[i])`
- `maxSum` me **best tak ka answer** save karo

---

## Complexity

| | |
|---|---|
| Time | O(n) |
| Space | O(1) |

---

## Solution

```cpp
// LeetCode 53 - Maximum Subarray
// Approach: Kadane's Algorithm
// Time: O(n) | Space: O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0] ;
        int currSum = nums[0] ;

        for ( int i = 1 ; i < nums.size() ; i++){
            currSum = max(nums[i] , currSum + nums[i]);
            maxSum = max(maxSum , currSum);
        }
        return maxSum ;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/maximum-subarray/)
