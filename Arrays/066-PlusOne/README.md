<div align="center">

# 66. Plus One

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Arrays-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Carry_Propagation-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given a large integer as digit array `digits`, **increment by one** and return resulting digits array.

---

## Examples

| Input | Output |
|-------|--------|
| [1,2,3] | [1,2,4] |
| [4,3,2,1] | [4,3,2,2] |
| [9] | [1,0] |

---

## Approach — Carry Propagation

```
digits = [9]

i=0: digits[0]=9 → not < 9, set to 0
Loop ends, no early return
Insert 1 at beginning → [1, 0] ✓
```
digits = [1,2,3]
i=2: digits[2]=3 < 9 → digits[2]++ = 4

return [1,2,4] immediately ✓

- Right se left traverse karo
- Digit `< 9` ho to `+1` karke return karo
- `9` ho to `0` set karo aur aage badho (carry)
- Sab `9` the to end me `1` insert karo front me

---

## Complexity

| | |
|---|---|
| Time | O(n) |
| Space | O(1) (worst case O(n) for insert) |

---

## Solution

```cpp
// LeetCode 66 - Plus One
// Approach: Carry Propagation
// Time: O(n) | Space: O(1)

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++; 
                return digits;
            }
            digits[i] = 0; 
        }

        digits.insert(digits.begin(), 1);
        return digits;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/plus-one/)
