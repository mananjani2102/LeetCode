<div align="center">

# 1784. Check if Binary String Has at Most One Segment of Ones

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Strings-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Count_Segment_Starts-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given a binary string s without leading zeros, return true if s contains at most one contiguous segment of ones.

---

## Examples

| Input | Output |
|-------|--------|
| "1001" | false |
| "110" | true |

---

## Approach - Count Segment Starts

Har naye segment ki shuruwat tab hoti hai jab current character '1' ho aur (ya to ye string ka pehla character ho ya pichla character '0' ho). Aise har shuruwat ko count karo. Agar total count 1 se kam ya equal hai to true, warna false.

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
    bool checkOnesSegment(string s) {
        int count = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1' && (i == 0 || s[i - 1] == '0')) {
                count++;
            }
        }

        if (count <= 1) {
            return true;
        } else {
            return false;
        }
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/)
