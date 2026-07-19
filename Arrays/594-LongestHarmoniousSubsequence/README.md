<div align="center">

# 594. Longest Harmonious Subsequence

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Arrays-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-HashMap_Frequency-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

A harmonious array has max-min difference exactly 1. Given nums, return length of longest harmonious subsequence.

---

## Examples

| Input | Output |
|-------|--------|
| [1,3,2,2,5,2,3,7] | 5 |
| [1,2,3,4] | 2 |
| [1,1,1,1] | 0 |

---

## Approach - HashMap Frequency Count

nums = [1,3,2,2,5,2,3,7]

freq: 1:1, 3:2, 2:3, 5:1, 7:1

Check pairs (num, num+1):
1,2 → freq[1]+freq[2] = 1+3 = 4
2,3 → freq[2]+freq[3] = 3+2 = 5 ← max
3,4 → freq[4] doesn't exist, skip
5,6 → freq[6] doesn't exist, skip

Answer = 5 ✓ (subsequence [3,2,2,2,3])


- Har number ka **frequency** HashMap me store karo
- Har unique number `num` ke liye check karo ki `num+1` bhi map me hai ya nahi
- Agar hai to dono ka combined count (`freq[num] + freq[num+1]`) **harmonious subsequence length** ho sakta hai (kyunki max-min difference exactly 1 hoga)
- Sabse bada aisa combined count hi answer hai

---

## Complexity

| | |
|---|---|
| Time | O(n) |
| Space | O(n) |

---

## Solution

```cpp
class Solution {
public:
    int findLHS(vector<int>& nums) {

        unordered_map<int, int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        int ans = 0;

        for (auto it : freq) {

            int num = it.first;

            if (freq.find(num + 1) != freq.end()) {

                int length = freq[num] + freq[num + 1];

                ans = max(ans, length);
            }
        }

        return ans;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/longest-harmonious-subsequence/)
