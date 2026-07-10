<div align="center">

# 205. Isomorphic Strings

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Strings-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Two_HashMaps-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given strings s and t, determine if they are isomorphic - characters in s can be replaced to get t, with a strict one-to-one mapping.

---

## Examples

| Input | Output |
|-------|--------|
| s="egg", t="add" | true |
| s="f11", t="b23" | false |
| s="paper", t="title" | true |

---

## Approach - Two HashMaps for Bidirectional Mapping
s = "egg"   t = "add"
i=0: 'e'->'a' → mapST[e]=a, mapTS[a]=e
i=1: 'g'->'d' → mapST[g]=d, mapTS[d]=g
i=2: 'g'->'d' → already mapST[g]=d matches ✓
All consistent → true

- Do HashMaps rakho: `s→t` mapping aur `t→s` mapping
- Har character pair ke liye check karo dono directions me **consistent** hai ya nahi
- Agar `mapST[c1]` already exist karta hai aur `c2` se match nahi karta → `false`
- Same check `mapTS` ke liye bhi (taaki do characters same target pe map na hon)

---

## Complexity

| | |
|---|---|
| Time | O(n) |
| Space | O(1) fixed alphabet size |

---

## Solution

```cpp
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, char> mapST;
        unordered_map<char, char> mapTS;

        for (int i = 0; i < s.size(); i++) {
            char c1 = s[i];
            char c2 = t[i];

            if (mapST.count(c1) && mapST[c1] != c2) return false;
            if (mapTS.count(c2) && mapTS[c2] != c1) return false;

            mapST[c1] = c2;
            mapTS[c2] = c1;
        }

        return true;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/isomorphic-strings/)
