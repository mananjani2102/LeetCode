<div align="center">

# 8. String to Integer (atoi)

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Strings-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Manual_Parsing-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Implement `myAtoi(string s)` jo string ko **32-bit signed integer** me convert kare — leading whitespace skip karo, sign check karo, digits parse karo, aur overflow ko range me clamp karo.

---

## Examples

| Input | Output |
|-------|--------|
| "42" | 42 |
| "   -042" | -42 |
| "1337c0d3" | 1337 |
| "0-1" | 0 |
| "words and 987" | 0 |

---

## Approach — Manual Parsing
s = "   -042"
Step 1 - Skip whitespace:

i moves past spaces → "−042"
Step 2 - Check sign:

'-' found → sign = -1, i++
Step 3 - Read digits:

'0' → result=0

'4' → result=4

'2' → result=42
Step 4 - Apply sign:

final = -1 * 42 = -42 ✓

- Leading **whitespace** skip karo
- `+` / `-` check karo sign ke liye
- Digits ko `result = result*10 + digit` se build karo
- Har step pe **overflow check** karo (`INT_MAX` / `INT_MIN`)
- Non-digit mile to loop rok do

---

## Complexity

| | |
|---|---|
| Time | O(n) |
| Space | O(1) |

---

## Solution

```cpp
// LeetCode 8 - String to Integer (atoi)
// Approach: Manual Parsing
// Time: O(n) | Space: O(1)

class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        long result = 0;
        int sign = 1;

        while (i < n && s[i] == ' ') i++;

        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');
            if (sign == 1 && result > INT_MAX) return INT_MAX;
            if (sign == -1 && -result < INT_MIN) return INT_MIN;
            i++;
        }

        return (int)(sign * result);
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/string-to-integer-atoi/)
