<div align="center">

# 387. First Unique Character in a String

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Strings-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Frequency_Array-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given a string `s`, find the first non-repeating character and return its index. Agar koi na ho to -1 return karo.

---

## Examples

| Input | Output |
|-------|--------|
| "leetcode" | 0 |
| "loveleetcode" | 2 |
| "aabb" | -1 |

---

## Approach - Frequency Array

26 size ka frequency array banao. Pehle pass me har character ka count karo. Dusre pass me jo character ka count 1 ho, uska index return karo.

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
    int firstUniqChar(string s) {
        vector<int> freq(26, 0);
        for(char c : s) {
            freq[c - 'a']++;
        }
        for(int i = 0; i < s.size(); i++) {
            if(freq[s[i] - 'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/first-unique-character-in-a-string/)
