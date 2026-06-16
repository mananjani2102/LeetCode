<div align="center">

# 1768. Merge Strings Alternately

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Strings-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Two_Pointers-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Merge two strings word1 and word2 by alternating letters, starting with word1. If one string is longer, append remaining letters at the end.

---

## Examples

| Input | Output |
|-------|--------|
| word1="abc", word2="pqr" | "apbqcr" |
| word1="ab", word2="pqrs" | "apbqrs" |
| word1="abcd", word2="pq" | "apbqcd" |

---

## Approach - Two Pointers

Dono strings me ek ek pointer rakho (i aur j). Jab tak dono me characters bache hain, alternate karke add karo - pehle word1 ka character, fir word2 ka. Jab ek string khatam ho jaye to dusri string ke bache hue characters seedha end me append kar do.

---

## Complexity

| | |
|---|---|
| Time | O(n + m) |
| Space | O(n + m) |

---

## Solution

```cpp
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int i = 0, j = 0;
        while (i < word1.size() && j < word2.size()) {
            ans += word1[i++];
            ans += word2[j++];
        }
        while (i < word1.size()) {
            ans += word1[i++];
        }
        while (j < word2.size()) {
            ans += word2[j++];
        }
        return ans;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/merge-strings-alternately/)
