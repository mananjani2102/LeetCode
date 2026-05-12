<div align="center">

# 14. Longest Common Prefix

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Strings-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Vertical_Scanning-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Find the **longest common prefix** string amongst an array of strings. Agar common prefix na ho to empty string `""` return karo.

---

## Examples

| Input | Output |
|-------|--------|
| ["flower","flow","flight"] | "fl" |
| ["dog","racecar","car"] | "" |

---

## Approach — Vertical Scanning
strs = ["flower", "flow", "flight"]
i=0: 'f' → sab me 'f' match ✓

i=1: 'l' → sab me 'l' match ✓

i=2: 'o' vs 'o' vs 'i' → "flight" me mismatch ✗

→ return strs[0].substr(0, 2) = "fl" ✓

- Pehle string ke har character ko **column-wise** check karo
- Baaki sab strings me same position pe same character ho to match
- Mismatch ya string khatam → wahan tak ka prefix return karo
- Sab match ho gaye to pehli string poori return karo

---

## Complexity

| | |
|---|---|
| Time | O(n × m) — n = strings count, m = shortest string length |
| Space | O(1) |

---

## Solution

```cpp
// LeetCode 14 - Longest Common Prefix
// Approach: Vertical Scanning
// Time: O(n*m) | Space: O(1)

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        for (int i = 0; i < strs[0].size(); i++) {
            char current = strs[0][i];

            for (int j = 1; j < strs.size(); j++) {
                if (i >= strs[j].size() || strs[j][i] != current) {
                    return strs[0].substr(0, i);
                }
            }
        }

        return strs[0];
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/longest-common-prefix/)
