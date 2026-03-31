<div align="center">

# 345. Reverse Vowels of a String

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Strings-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Two_Pointers-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

String `s` mein sirf vowels ko reverse karo — baaki characters apni jagah rahenge.  
Vowels: `a e i o u` (uppercase + lowercase dono).

---

## Examples

| Input | Output | Explanation |
|-------|--------|-------------|
| `"IceCreAm"` | `"AceCreIm"` | vowels `[I,e,e,A]` → reversed `[A,e,e,I]` |
| `"leetcode"` | `"leotcede"` | vowels `[e,e,o,e]` → reversed `[e,o,e,e]` |

---

## Approach — Two Pointers

```
s = "I c e C r e A m"
     ↑               ↑
   left            right

Step 1: left='I'(vowel), right='m'(not) → right--
Step 2: left='I'(vowel), right='A'(vowel) → swap → "A c e C r e I m"
Step 3: left='c'(not)  → left++
Step 4: left='e'(vowel), right='e'(vowel) → swap → no change
Step 5: left >= right → STOP

Result: "AceCreIm" ✓
```

- `left` aur `right` dono pointers vowel dhundte hain
- Dono vowel mile to swap karo
- Beech mein milne tak repeat karo

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
    string reverseVowels(string s) {
        unordered_set<char> vowels = {'a','e','i','o','u','A','E','I','O','U'};
        int left = 0, right = s.size() - 1;

        while (left < right) {
            while (left < right && !vowels.count(s[left]))  left++;
            while (left < right && !vowels.count(s[right])) right--;
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

[LeetCode Problem](https://leetcode.com/problems/reverse-vowels-of-a-string/)