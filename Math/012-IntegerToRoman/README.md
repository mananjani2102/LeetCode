<div align="center">

# 12. Integer to Roman

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Math-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Greedy_Value_Symbol_Pairs-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given integer num, convert it to Roman numeral using symbols I, V, X, L, C, D, M with subtractive notation rules (IV, IX, XL, XC, CD, CM).

---

## Examples

| Input | Output |
|-------|--------|
| 3749 | "MMMDCCXLIX" |
| 58 | "LVIII" |
| 1994 | "MCMXCIV" |

---

## Approach - Greedy with Value-Symbol Pairs
num = 1994
value=1000: 1994>=1000 → result="M", num=994
value=900:  994>=900   → result="MCM", num=94
value=500,400,100: skip (94<100)
value=90:   94>=90     → result="MCMXC", num=4
value=50,40,10,9: skip (4<9)
value=5: skip (4<5)
value=4:    4>=4       → result="MCMXCIV", num=0
Result = "MCMXCIV" ✓

- Pehle se ek **value-symbol pairs list** banao decreasing order me — including **subtractive forms** (900=CM, 400=CD, 90=XC, 40=XL, 9=IX, 4=IV)
- Har pair ke liye, jab tak `num >= value` ho, symbol ko result me add karte raho aur `num` se value subtract karo
- Ye **greedy approach** subtractive cases ko automatically handle kar leta hai kyunki wo list me pehle se maujood hain

---

## Complexity

| | |
|---|---|
| Time | O(1) — fixed 13 symbols max iterations |
| Space | O(1) |

---

## Solution

```cpp
class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> valueSymbols = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };

        string result = "";

        for (auto& [value, symbol] : valueSymbols) {
            while (num >= value) {
                num -= value;
                result += symbol;
            }
        }

        return result;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/integer-to-roman/)
