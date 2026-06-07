<div align="center">

# 1365. How Many Numbers Are Smaller Than the Current Number

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Arrays-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Counting_Sort_Prefix_Sum-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

For each nums[i], count how many numbers in the array are smaller than it. Return the answer as an array.

---

## Examples

| Input | Output |
|-------|--------|
| [8,1,2,2,3] | [4,0,1,1,3] |
| [6,5,4,8] | [2,1,0,3] |
| [7,7,7,7] | [0,0,0,0] |

---

## Approach - Counting Sort + Prefix Sum

Values 0-100 ke range me hain, isliye frequency array banao. Har number ka count store karo, fir prefix sum banao - freq[i] ab batata hai ki kitne numbers hain jo i se chote ya equal hain. Har nums[i] ke liye freq[num-1] dekho - yeh exactly utne numbers hain jo num se chote hain.

---

## Complexity

| | |
|---|---|
| Time | O(n) |
| Space | O(1) fixed 101 size array |

---

## Solution

```cpp
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> freq(101, 0);

        for (int num : nums) {
            freq[num]++;
        }

        for (int i = 1; i <= 100; i++) {
            freq[i] += freq[i - 1];
        }

        vector<int> ans;

        for (int num : nums) {
            if (num == 0)
                ans.push_back(0);
            else
                ans.push_back(freq[num - 1]);
        }

        return ans;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/)
