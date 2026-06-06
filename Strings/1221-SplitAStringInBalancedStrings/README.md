<div align="center">

# 1221. Split a String in Balanced Strings

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Strings-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Counter_Balance-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given a balanced string s (equal L and R), split it into maximum number of balanced substrings.

---

## Examples

| Input | Output |
|-------|--------|
| "RLRRLLRLRL" | 4 |
| "RLRRRLLRLL" | 2 |
| "LLLLRRRR" | 1 |

---

## Approach - Counter Balance

Ek balance counter rakho jo 'R' aane par badhta hai aur 'L' aane par ghatta hai. Jab bhi ye balance 0 ho jaye, matlab abhi tak ka substring balanced hai (equal L and R) - count badha do. Greedy approach hai: jaise hi balance 0 hota hai, wahi split point sabse achha hai kyunki usse aage zyada splits possible ho sakte hain.

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
    int balancedStringSplit(string s) {
        int balance = 0;
        int count = 0;

        for (char ch : s) {
            if (ch == 'R')
                balance++;
            else
                balance--;

            if (balance == 0)
                count++;
        }

        return count;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/split-a-string-in-balanced-strings/)
