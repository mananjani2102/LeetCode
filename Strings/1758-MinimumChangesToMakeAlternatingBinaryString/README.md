<div align="center">

# 1758. Minimum Changes To Make Alternating Binary String

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Strings-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Count_Mismatches-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given binary string s, return minimum operations (flips) needed to make it alternating (no two adjacent characters equal).

---

## Examples

| Input | Output |
|-------|--------|
| "0100" | 1 |
| "10" | 0 |
| "1111" | 2 |

---

## Approach - Count Mismatches with Two Patterns

s = "1111"

Pattern "0101...": expected[0]='0',[1]='1',[2]='0',[3]='1'
Actual: '1','1','1','1'
Mismatches: index0(1vs0)✓mismatch, index1(1vs1)match, index2(1vs0)mismatch, index3(1vs1)match
countStartWith0 = 2

Pattern "1010...": countStartWith1 = 4-2 = 2

min(2,2) = 2 ✓


- Sirf **do possible alternating patterns** ho sakte hain: `"0101..."` ya `"1010..."`
- Ek pattern (`"0101..."`) ke against mismatches count karo — jo bhi position `s[i]` expected value se mismatch kare, count badhao
- Doosre pattern (`"1010..."`) ke mismatches automatically `n - countStartWith0` honge (kyunki har position ya to ek pattern se match karega ya doosre se)
- Dono me se **minimum** operations chahiye honge

---

## Complexity

| | |
|---|---|
| Time | O(n) |
| Space | O(1) |

---

## Solution

```cpp
class Solution {
public:
    int minOperations(string s) {
        int countStartWith0 = 0;

        for (int i = 0; i < s.size(); i++) {
            char expected = (i % 2 == 0) ? '0' : '1';
            if (s[i] != expected) {
                countStartWith0++;
            }
        }

        int countStartWith1 = s.size() - countStartWith0;

        return min(countStartWith0, countStartWith1);
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/)
