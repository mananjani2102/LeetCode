<div align="center">

# 45. Jump Game II

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Arrays-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Greedy_BFS_Style-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given array nums where nums[i] is max jump length from index i, return minimum number of jumps to reach last index. Reaching last index is guaranteed.

---

## Examples

| Input | Output |
|-------|--------|
| [2,3,1,1,4] | 2 |
| [2,3,0,1,4] | 2 |

---

## Approach - Greedy BFS Style (Level by Level)
nums = [2,3,1,1,4]
i=0: farthest=max(0,0+2)=2
i==currentEnd(0) → jumps=1, currentEnd=2
i=1: farthest=max(2,1+3)=4
i!=currentEnd(2) → continue
i=2: farthest=max(4,2+1)=4
i==currentEnd(2) → jumps=2, currentEnd=4
i=3: farthest=max(4,3+1)=4
i!=currentEnd(4) → continue
Loop ends (i<n-1=4)
Answer = 2 ✓

- Ye **BFS jaisa level-by-level** approach hai bina explicit BFS ke
- `currentEnd` batata hai current "jump" se kitna door tak pahunch sakte ho
- `farthest` track karta hai next jump se kitna door tak ja sakte ho
- Jab `i` `currentEnd` tak pahunch jata hai, matlab current level khatam — ek **jump count** badhao aur `currentEnd` ko `farthest` set karo
- Greedy approach hamesha optimal hota hai kyunki har jump se **maximum reach** maximize karte hain

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
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0;
        int currentEnd = 0;
        int farthest = 0;

        for (int i = 0; i < n - 1; i++) {
            farthest = max(farthest, i + nums[i]);

            if (i == currentEnd) {
                jumps++;
                currentEnd = farthest;
            }
        }

        return jumps;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/jump-game-ii/)
