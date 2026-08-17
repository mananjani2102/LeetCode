<div align="center">

# 945. Minimum Increment to Make Array Unique

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Arrays-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Sort_Greedy-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given integer array nums, increment elements (by 1 each move) to make every value unique. Return minimum number of moves.

---

## Examples

| Input | Output |
|-------|--------|
| [1,2,2] | 1 |
| [3,2,1,2,1,7] | 6 |

---

## Approach - Sort Greedy

nums = [3,2,1,2,1,7]
Sort → [1,1,2,2,3,7]

i=1: nums[1]=1<=nums[0]=1 → needed=1+1-1=1, moves=1, nums[1]=2
array now: [1,2,2,2,3,7]
i=2: nums[2]=2<=nums[1]=2 → needed=2+1-2=1, moves=2, nums[2]=3
array now: [1,2,3,2,3,7]
i=3: nums[3]=2<=nums[2]=3 → needed=3+1-2=2, moves=4, nums[3]=4
array now: [1,2,3,4,3,7]
i=4: nums[4]=3<=nums[3]=4 → needed=4+1-3=2, moves=6, nums[4]=5
array now: [1,2,3,4,5,7]
i=5: nums[5]=7>nums[4]=5 → no change needed

Answer = 6 ✓


- Array ko **sort** karo — isse duplicates aur conflicts ek dusre ke paas aa jate hain
- Har element ko previous element se compare karo — agar current **<=  previous**, to use `previous+1` tak increment karo
- Har increment ki cost track karo (`needed = previous+1 - current`)
- Ye **greedy approach** hamesha optimal hai kyunki sorted array me minimum increments hi kaafi hote hain unique banane ke liye

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
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int moves = 0;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] <= nums[i - 1]) {
                int needed = nums[i - 1] + 1 - nums[i];
                moves += needed;
                nums[i] = nums[i - 1] + 1;
            }
        }

        return moves;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/minimum-increment-to-make-array-unique/)
