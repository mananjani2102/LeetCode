<div align="center">

# 1431. Kids With the Greatest Number of Candies

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Arrays-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Find_Max_Compare-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given candies array and extraCandies, return boolean array where result[i] is true if kid i, after getting all extraCandies, would have the greatest number of candies.

---

## Examples

| Input | Output |
|-------|--------|
| candies=[2,3,5,1,3], extraCandies=3 | [true,true,true,false,true] |
| candies=[4,2,1,1,2], extraCandies=1 | [true,false,false,false,false] |
| candies=[12,1,12], extraCandies=10 | [true,false,true] |

---

## Approach - Find Max Compare

candies = [2,3,5,1,3] extraCandies=3

maxCandies = max(candies) = 5

Check each kid:
2+3=5 >= 5 → true
3+3=6 >= 5 → true
5+3=8 >= 5 → true
1+3=4 >= 5 → false
3+3=6 >= 5 → true

Result = [true,true,true,false,true] ✓


- Pehle array ka **maximum** candies value nikalo
- Har kid ke liye check karo: `candies[i] + extraCandies >= maxCandies`
- Agar true hai to us kid ke paas extra candies milne ke baad bhi (ya sabse zyada) greatest number of candies hongi

---

## Complexity

| | |
|---|---|
| Time | O(n) |
| Space | O(n) for output array |

---

## Solution

```cpp
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandies = *max_element(candies.begin(), candies.end());

        vector<bool> result;

        for (int candy : candies) {
            result.push_back(candy + extraCandies >= maxCandies);
        }

        return result;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/)
