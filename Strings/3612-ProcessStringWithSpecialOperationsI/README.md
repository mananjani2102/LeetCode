<div align="center">

# 3612. Process String with Special Operations I

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Strings-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Simulation-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given string s with lowercase letters and special characters *, #, %, build result string: letters get appended, * removes last char, # duplicates the whole string, % reverses it.

---

## Examples

| Input | Output |
|-------|--------|
| "a#b%*" | "ba" |
| "z*#" | "" |

---

## Approach - Simulation

String ko left se right process karo character by character. Lowercase letter mile to result me append karo. '*' mile to last character remove karo (agar result empty na ho). '#' mile to result ko apne aap se duplicate karo (result += result). '%' mile to result ko reverse kar do. Sab operations apply hone ke baad final result return karo.

---

## Complexity

| | |
|---|---|
| Time | O(2^k * n) worst case due to repeated doubling |
| Space | O(n) |

---

## Solution

```cpp
class Solution {
public:
    string processStr(string s) {
        string result;

        for (char ch : s) {
            if (ch >= 'a' && ch <= 'z') {
                result += ch;
            }
            else if (ch == '*') {
                if (!result.empty()) {
                    result.pop_back();
                }
            }
            else if (ch == '#') {
                result += result;
            }
            else if (ch == '%') {
                reverse(result.begin(), result.end());
            }
        }

        return result;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/process-string-with-special-operations-i/)
