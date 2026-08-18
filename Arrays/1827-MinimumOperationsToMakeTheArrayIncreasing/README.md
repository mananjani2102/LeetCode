<div align="center">

# 1827. Minimum Operations to Make the Array Increasing

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Arrays-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Greedy-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given integer array nums, increment elements (by 1 each move) to make the array strictly increasing. Return minimum number of operations.

---

## Examples

| Input | Output |
|-------|--------|
| [1,1,1] | 3 |
| [1,5,2,4,1] | 14 |
| [8] | 0 |

---

## Approach - Greedy
nums = [1,5,2,4,1]

i=1: nums[1]=5 > nums[0]=1 → no change needed
i=2: nums[2]=2<=nums[1]=5 → needed=5+1-2=4, operations=4, nums[2]=6
array now: [1,5,6,4,1]
i=3: nums[3]=4<=nums[2]=6 → needed=6+1-4=3, operations=7, nums[3]=7
array now: [1,5,6,7,1]
i=4: nums[4]=1<=nums[3]=7 → needed=7+1-1=7, operations=14, nums[4]=8
array now: [1,5,6,7,8]

Answer = 14 ✓


- Array ko **left se right traverse** karo — sorting ki zarurat nahi kyunki original order maintain karna hai
- Har element ko previous element se compare karo — agar current **<= previous**, to use `previous+1` tak increment karo
- Har increment ki cost track karo (`needed = previous+1 - current`)
- Ye **greedy approach** hamesha optimal hai kyunki ek hi pass me minimum operations se strictly increasing array ban jata hai

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
    int minOperations(vector<int>& nums) {
        int operations = 0;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] <= nums[i - 1]) {
                int needed = nums[i - 1] + 1 - nums[i];
                operations += needed;
                nums[i] = nums[i - 1] + 1;
            }
        }

        return operations;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/minimum-operations-to-make-the-array-increasing/)
