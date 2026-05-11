<div align="center">

# 13. Roman to Integer

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Strings-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-HashMap-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given a roman numeral `s`, convert it to an **integer**. Symbols: I=1, V=5, X=10, L=50, C=100, D=500, M=1000.

---

## Examples

| Input | Output |
|-------|--------|
| "III" | 3 |
| "LVIII" | 58 |
| "MCMXCIV" | 1994 |

---

## Approach — HashMap + Subtraction Check
s = "MCMXCIV"
M=1000  → next C(100) < M → add 1000        total=1000

C=100   → next M(1000) > C → subtract 100   total=900

M=1000  → next X(10) < M → add 1000         total=1900

X=10    → next C(100) > X → subtract 10     total=1890

C=100   → next I(1) < C → add 100           total=1990

I=1     → next V(5) > I → subtract 1        total=1989

V=5     → last char → add 5                 total=1994 ✓

- Har character ki value HashMap se lo
- Agar current value **next se chhoti** ho → subtract karo
- Warna **add** karo
- Last character hamesha add hota hai

---

## Complexity

| | |
|---|---|
| Time | O(n) |
| Space | O(1) |

---

## Solution

```cpp
// LeetCode 13 - Roman to Integer
// Approach: HashMap + Subtraction Check
// Time: O(n) | Space: O(1)

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> values = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int total = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (i + 1 < n && values[s[i]] < values[s[i + 1]]) {
                total -= values[s[i]];
            } else {
                total += values[s[i]];
            }
        }

        return total;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/roman-to-integer/)
