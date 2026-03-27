<div align="center">

# 3010. Divide an Array Into Subarrays With Minimum Cost I

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Arrays-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Brute_Force-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Array `nums` ko **3 contiguous subarrays** mein divide karo.  
Har subarray ki cost uska **pehla element** hoti hai.  
Teen subarrays ki minimum possible total cost return karo.

---

## Examples

| Input | Output | Best Split |
|-------|--------|------------|
| `[1,2,3,12]` | `6`  | `[1] [2] [3,12]` → 1+2+3 |
| `[5,4,3]`    | `12` | `[5] [4] [3]`    → 5+4+3 |
| `[10,3,1,1]` | `12` | `[10,3] [1] [1]` → 10+1+1 |

---

## Approach — Brute Force

```
nums = [1, 2, 3, 12]

Cost = nums[0] + nums[i] + nums[j]   (i < j, both > 0)

i=1, j=2: 1 + 2 + 3  = 6   ← min
i=1, j=3: 1 + 2 + 12 = 15
i=2, j=3: 1 + 3 + 12 = 16

Answer: 6 ✓
```

- `nums[0]` hamesha pehli subarray ka cost hoga
- `nums[i]` aur `nums[j]` doosri aur teesri subarray ke starting elements hain
- Saare valid `(i, j)` pairs try karo aur minimum dhundo

---

## Complexity

| | |
|---|---|
| Time | O(n²) |
| Space | O(1) |

> n ≤ 50 hai, isliye O(n²) perfectly fine hai

---

## Solution

```cpp
class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n   = nums.size();
        int ans = INT_MAX;

        for (int i = 1; i < n; i++)
            for (int j = i + 1; j < n; j++)
                ans = min(ans, nums[0] + nums[i] + nums[j]);

        return ans;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-i/)