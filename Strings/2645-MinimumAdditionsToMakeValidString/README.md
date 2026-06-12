<div align="center">

# 2645. Minimum Additions to Make Valid String

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Strings-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Greedy_Block_Counting-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given a string word, return the minimum number of letters (a, b, c) that must be inserted so it becomes valid (formed by concatenating "abc" multiple times).

---

## Examples

| Input | Output |
|-------|--------|
| "b" | 2 |
| "aaa" | 6 |
| "abc" | 0 |

---

## Approach - Greedy Block Counting

Final valid string hamesha "abc" blocks ka concatenation hota hai, jaha har block ke andar letters strictly increasing order me hain (a < b < c). Jab bhi current character previous character se chota ya equal aata hai, matlab naya "abc" block start ho gaya - blocks count badhao. End me total blocks * 3 hi minimum required length hai, usse word ki current length minus karne se answer milta hai.

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
    int addMinimum(string word) {
        int blocks = 1;

        for (int i = 1; i < word.length(); i++) {
            if (word[i] <= word[i - 1]) {
                blocks++;
            }
        }

        return blocks * 3 - word.length();
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/minimum-additions-to-make-valid-string/)
