<div align="center">

# 459. Repeated Substring Pattern

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Strings-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-String_Concatenation_Trick-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given string s, check if it can be built by repeating some substring multiple times.

---

## Examples

| Input | Output |
|-------|--------|
| "abab" | true |
| "aba" | false |
| "abcabcabcabc" | true |

---

## Approach - String Concatenation Trick
s = "abab"
doubled = (s+s) = "abababab"
Remove first aur last char: "bababa"
Check: does "bababa" contain "abab"?
"bababa" → "ba[bab]a" wait let's check properly
Actually: "bababa".find("abab") → found at index 1 ✓
→ true

- Trick: `s` ko apne se **do baar jodo** aur first-last character hata do
- Agar wo naya string original `s` ko **contain** karta hai to `s` repeated pattern se bana hai
- Ye kaam karta hai kyunki agar `s` truly repeated hai, to wo doubled string ke beech me kahin milega
- `find()` se check karo

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
    bool repeatedSubstringPattern(string s) {
        string doubled = (s + s).substr(1, 2 * s.size() - 2);
        return doubled.find(s) != string::npos;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/repeated-substring-pattern/)
