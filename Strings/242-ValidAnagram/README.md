<div align="center">

# 242. Valid Anagram

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Strings-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Frequency_Array-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given strings s and t, return true if t is an anagram of s (same characters, same frequency, different order allowed).

---

## Examples

| Input | Output |
|-------|--------|
| s="anagram", t="nagaram" | true |
| s="rat", t="car" | false |

---

## Approach - Frequency Array
s = "anagram"   t = "nagaram"
Same length ✓
s se increment: a:3, n:1, g:1, r:1, m:1
t se decrement: sabhi counts wapas 0 ho jayenge agar anagram hai
Check all freq[i]==0 → true ✓

- Pehle length check karo — different length ho to `false`
- 26 size ka frequency array banao
- `s` ke characters se **increment** karo, `t` ke characters se **decrement** karo
- End me sabhi counts `0` hain to anagram hai, warna nahi

**Follow-up (Unicode):** Fixed 26-size array kaam nahi karega Unicode ke liye. Uske jagah `unordered_map<char32_t, int>` (ya language-appropriate hashmap) use karo jo dynamically har character ka count track kare, chahe wo kitna bhi bada character set ho.

---

## Complexity

| | |
|---|---|
| Time | O(n) |
| Space | O(1) fixed 26 size array |

---

## Solution

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        vector<int> freq(26, 0);

        for (char ch : s) {
            freq[ch - 'a']++;
        }

        for (char ch : t) {
            freq[ch - 'a']--;
        }

        for (int count : freq) {
            if (count != 0) return false;
        }

        return true;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/valid-anagram/)
