<div align="center">

# 392. Is Subsequence

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Strings-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Two_Pointers-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given strings s and t, return true if s is a subsequence of t (can be formed by deleting some characters from t without changing relative order).

---

## Examples

| Input | Output |
|-------|--------|
| s="abc", t="ahbgdc" | true |
| s="axc", t="ahbgdc" | false |

---

## Approach - Two Pointers
s = "abc"   t = "ahbgdc"
i=0,j=0: s[0]='a'==t[0]='a' → i=1, j=1
i=1,j=1: s[1]='b'!=t[1]='h' → j=2
i=1,j=2: s[1]='b'==t[2]='b' → i=2, j=3
i=2,j=3: s[2]='c'!=t[3]='g' → j=4
i=2,j=4: s[2]='c'!=t[4]='d' → j=5
i=2,j=5: s[2]='c'==t[5]='c' → i=3, j=6
i==s.size() → true ✓

- `i` pointer `s` ke liye, `j` pointer `t` ke liye
- `t` traverse karte raho, jab `s[i] == t[j]` mile to `i` badhao
- `j` hamesha aage badhta rahega
- Agar `i` `s` ke end tak pahunch gaya to `s` `t` ka subsequence hai

**Follow-up:** Bahut saare `s` strings check karne ke liye, `t` ka precompute character index map bana lo (Binary Search approach) taaki har query O(log n) me ho.

---

## Complexity

| | |
|---|---|
| Time | O(n) where n = length of t |
| Space | O(1) |

---

## Solution

```cpp
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;

        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j]) {
                i++;
            }
            j++;
        }

        return i == s.size();
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/is-subsequence/)
