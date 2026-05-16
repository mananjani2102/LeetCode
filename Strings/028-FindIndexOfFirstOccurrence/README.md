<div align="center">

# 28. Find the Index of the First Occurrence in a String

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Strings-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Brute_Force-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given two strings `needle` and `haystack`, return the **index of first occurrence** of `needle` in `haystack`, ya `-1` agar nahi mila.

---

## Examples

| Input | Output |
|-------|--------|
| haystack="sadbutsad", needle="sad" | 0 |
| haystack="leetcode", needle="leeto" | -1 |

---

## Approach — Brute Force Substring Search

```
haystack = "sadbutsad"   needle = "sad"

i=0: compare "sad" with haystack[0..2]="sad" → match! return 0 ✓
```
haystack = "leetcode"   needle = "leeto"
i=0: "leeto" vs "leetc" → mismatch at index 4 ('o' vs 'c')

i=1: "eetco" vs "eetco" wait check further → no match anywhere

→ return -1

- Har starting index `i` se needle ko match karne ki koshish karo
- Andar wala loop character by character compare karta hai
- Pura needle match ho to `i` return karo
- Kahin match na ho to `-1`

---

## Complexity

| | |
|---|---|
| Time | O(n × m) |
| Space | O(1) |

---

## Solution

```cpp
// LeetCode 28 - Find the Index of the First Occurrence in a String
// Approach: Brute Force Substring Search
// Time: O(n*m) | Space: O(1)

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        for(int i = 0; i <= n - m; i++) {
            int j = 0;
            while(j < m && haystack[i + j] == needle[j]) {
                j++;
            }
            if(j == m){
                return i ;
            }
        }
        return -1;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/)
