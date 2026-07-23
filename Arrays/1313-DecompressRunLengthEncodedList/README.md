<div align="center">

# 1313. Decompress Run-Length Encoded List

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Arrays-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Simple_Iteration-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given run-length encoded list nums where pairs [freq, val] represent freq occurrences of val, decompress and return the full list.

---

## Examples

| Input | Output |
|-------|--------|
| [1,2,3,4] | [2,4,4,4] |
| [1,1,2,3] | [1,3,3] |

---

## Approach - Simple Iteration

nums = [1,2,3,4]

i=0: freq=1, val=2 → add "2" once → result=[2]
i=2: freq=3, val=4 → add "4" three times → result=[2,4,4,4]

Answer = [2,4,4,4] ✓


- Array ko **2 ke steps** me traverse karo — har step pe ek pair `(freq, val)` milta hai
- Har pair ke liye, `val` ko `freq` baar result me push karo
- Sabhi pairs process ho jane ke baad complete decompressed list mil jati hai

---

## Complexity

| | |
|---|---|
| Time | O(n) — where n is total output length |
| Space | O(n) for output |

---

## Solution

```cpp
class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> result;

        for (int i = 0; i < nums.size(); i += 2) {
            int freq = nums[i];
            int val = nums[i + 1];

            for (int j = 0; j < freq; j++) {
                result.push_back(val);
            }
        }

        return result;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/decompress-run-length-encoded-list/)
