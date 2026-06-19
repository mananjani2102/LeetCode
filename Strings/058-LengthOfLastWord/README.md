<div align="center">

# 58. Length of Last Word

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Strings-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Reverse_Traversal-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given string s of words and spaces, return the length of the last word.

---

## Examples

| Input | Output |
|-------|--------|
| "Hello World" | 5 |
| "   fly me   to   the moon  " | 4 |
| "luffy is still joyboy" | 6 |

---

## Approach - Reverse Traversal
s = "   fly me   to   the moon  "
Step 1 - Trailing spaces skip karo:

i moves from end until non-space found → points to 'n'
Step 2 - Word count karo:

'n','o','o','m' count → length = 4 ✓

- String ke end se start karo
- Pehle trailing spaces skip karo
- Fir non-space characters count karo jab tak space na mile
- Wahi length return karo

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
    int lengthOfLastWord(string s) {
        int length = 0;
        int i = s.size() - 1;

        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }

        return length;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/length-of-last-word/)
