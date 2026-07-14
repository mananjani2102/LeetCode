<div align="center">

# 217. Contains Duplicate

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Arrays-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-HashSet-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given integer array nums, return true if any value appears at least twice, false if all elements are distinct.

---

## Examples

| Input | Output |
|-------|--------|
| [1,2,3,1] | true |
| [1,2,3,4] | false |
| [1,1,1,3,3,4,3,2,4,2] | true |

---

## Approach - HashSet
nums = [1,2,3,1]
seen={}
num=1: not in seen → insert → seen={1}
num=2: not in seen → insert → seen={1,2}
num=3: not in seen → insert → seen={1,2,3}
num=1: already in seen! → return true ✓

- HashSet me har number ko check karo — agar pehle se **seen** hai to `true` return karo (duplicate mil gaya)
- Warna set me insert karke aage badho
- Poori array process ho gayi aur koi duplicate nahi mila to `false`

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
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;

        for (int num : nums) {
            if (seen.count(num)) {
                return true;
            }
            seen.insert(num);
        }

        return false;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/contains-duplicate/)
