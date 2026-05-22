<div align="center">

# 219. Contains Duplicate II

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Arrays-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-HashMap-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given an integer array `nums` and integer `k`, return `true` if two **distinct indices** `i` and `j` exist such that `nums[i] == nums[j]` and `abs(i - j) <= k`.

---

## Examples

| Input | Output |
|-------|--------|
| nums=[1,2,3,1], k=3 | true |
| nums=[1,0,1,1], k=1 | true |
| nums=[1,2,3,1,2,3], k=2 | false |

---

## Approach — HashMap (Index Tracking)
nums = [1,2,3,1], k = 3
i=0: mp={} → 1 not found → mp={1:0}

i=1: mp={1:0} → 2 not found → mp={1:0, 2:1}

i=2: mp={1:0,2:1} → 3 not found → mp={1:0,2:1,3:2}

i=3: mp has 1 at index 0 → i-mp[1] = 3-0 = 3 <= k(3) ✓

→ return true

- Har number ka **last seen index** HashMap me store karo
- Agar number pehle se mila ho aur `i - lastIndex <= k` → `true`
- Warna current index update kar do map me

---

## Complexity

| | |
|---|---|
| Time | O(n) |
| Space | O(n) |

---

## Solution

```cpp
// LeetCode 219 - Contains Duplicate II
// Approach: HashMap (Index Tracking)
// Time: O(n) | Space: O(n)

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            if (mp.count(nums[i]) && i - mp[nums[i]] <= k) {
                return true;
            }

            mp[nums[i]] = i;
        }

        return false;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/contains-duplicate-ii/)
