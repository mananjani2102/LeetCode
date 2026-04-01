<div align="center">

# 917. Reverse Only Letters

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Strings-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Two_Pointers-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

String `s` mein sirf **English letters** ko reverse karo.  
Baaki characters (digits, symbols) apni original position pe rahenge.

---

## Examples

| Input | Output |
|-------|--------|
| `"ab-cd"` | `"dc-ba"` |
| `"a-bC-dEf-ghIj"` | `"j-Ih-gfE-dCba"` |
| `"Test1ng-Leet=code-Q!"` | `"Qedo1ct-eeLg=ntse-T!"` |

---

## Approach — Two Pointers

```
s = "a b - c d"
     ↑       ↑
   left    right

Step 1: left='a'(letter), right='d'(letter) → swap → "d b - c a", left++, right--
Step 2: left='b'(letter), right='c'(letter) → swap → "d c - b a", left++, right--
Step 3: left='-'(not)    → left++
Step 4: left >= right → STOP

Result: "dc-ba" ✓
```

- `isalpha()` se check karo letter hai ya nahi
- Non-letter mile to pointer skip karo
- Dono letter mile to swap karo

> 344-ReverseString aur 345-ReverseVowels jaisa hi pattern —  
> sirf skip condition alag hai (`!isalpha` vs `!isVowel`)

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
    string reverseOnlyLetters(string s) {
        int left = 0, right = s.size() - 1;

        while (left < right) {
            while (left < right && !isalpha(s[left]))  left++;
            while (left < right && !isalpha(s[right])) right--;
            swap(s[left], s[right]);
            left++;
            right--;
        }

        return s;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/reverse-only-letters/)