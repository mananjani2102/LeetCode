<div align="center">

# 3271. Hash Divided String

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Strings-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Chunk_Processing-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given string s of length n and integer k (n divisible by k), divide s into n/k substrings of length k. For each substring, sum character hash values, mod 26, convert to character, build result.

---

## Examples

| Input | Output |
|-------|--------|
| s="abcd", k=2 | "bf" |
| s="mxz", k=3 | "i" |

---

## Approach - Chunk Processing with Sum and Modulo

s = "abcd" k=2

Chunk1: "ab" (i=0 to 1)
sum = (a-a)+(b-a) = 0+1 = 1
hashedChar = 1%26 = 1 → 'a'+1 = 'b'
result = "b"

Chunk2: "cd" (i=2 to 3)
sum = (c-a)+(d-a) = 2+3 = 5
hashedChar = 5%26 = 5 → 'a'+5 = 'f'
result = "bf"

Answer = "bf" ✓


- Outer loop se string ko **k-size chunks** me divide karo (`i += k`)
- Har chunk ke andar, sabhi characters ka **hash value sum** karo (`ch - 'a'` se index milta hai)
- Sum ko `%26` karke **hashedChar** nikalo
- Us numeric value ko wapas character me convert karo (`'a' + hashedChar`) aur result me append karo

---

## Complexity

| | |
|---|---|
| Time | O(n) |
| Space | O(n/k) for output string |

---

## Solution

```cpp
class Solution {
public:
    string stringHash(string s, int k) {
        string result = "";
        int n = s.size();

        for (int i = 0; i < n; i += k) {
            int sum = 0;

            for (int j = i; j < i + k; j++) {
                sum += (s[j] - 'a');
            }

            int hashedChar = sum % 26;
            result += (char)('a' + hashedChar);
        }

        return result;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/hash-divided-string/)
