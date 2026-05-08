<div align="center">

# 5. Longest Palindromic Substring

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Strings-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Expand_Around_Center-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given a string `s`, return the **longest palindromic substring** in `s`.

---

## Examples

| Input | Output |
|-------|--------|
| "babad" | "bab" |
| "cbbd" | "bb" |

---

## Approach — Expand Around Center
s = "babad"
Har character ko center maan kar

dono taraf expand karo (odd length)
i=2 ('b' center):

l=1,r=3 → s[1]='a', s[3]='a' match

l=0,r=4 → s[0]='b', s[4]='d' no match
Palindrome mila: "aba" (l=1 to r=3)

ya "bab" (l=0 to r=2)
Even length ke liye: l=i, r=i+1 se bhi try karo

- Har index ko **center** maan kar dono taraf expand karo
- Odd length ke liye: `l = i, r = i`
- Even length ke liye: `l = i, r = i+1`
- Jab tak `s[l] == s[r]` match kare, expand karte raho
- Sabse lamba palindrome track karo

---

## Complexity

| | |
|---|---|
| Time | O(n²) |
| Space | O(1) |

---

## Solution

```cpp
// LeetCode 5 - Longest Palindromic Substring
// Approach: Expand Around Center
// Time: O(n²) | Space: O(1)

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int start = 0, maxLen = 1;

        for (int i = 0; i < s.size(); i++) {
            int l = i, r = i;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                if (r - l + 1 > maxLen) {
                    start = l;
                    maxLen = r - l + 1;
                }
                l--;
                r++;
            }

            l = i, r = i + 1;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                if (r - l + 1 > maxLen) {
                    start = l;
                    maxLen = r - l + 1;
                }
                l--;
                r++;
            }
        }
        return s.substr(start, maxLen);
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/longest-palindromic-substring/)
