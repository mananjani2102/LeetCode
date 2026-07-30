<div align="center">

# 3163. String Compression III

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Strings-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Chunking_Max_9-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given word, compress by repeatedly taking max-length prefix of a single repeating character (at most 9 times), appending count+character to result.

---

## Examples

| Input | Output |
|-------|--------|
| "abcde" | "1a1b1c1d1e" |
| "aaaaaaaaaaaaaabb" | "9a5a2b" |

---

## Approach - Chunking Max 9 Repeats

word = "aaaaaaaaaaaaaabb" (14 a's, 2 b's)

i=0: currentChar='a', count consecutive 'a's but STOP at 9
count=9, i moves to 9
comp += "9a"

i=9: currentChar='a' (still 'a's left), count up to 5 more (total 14, already used 9)
count=5, i moves to 14
comp += "5a"

i=14: currentChar='b', count=2, i moves to 16
comp += "2b"

Result = "9a5a2b" ✓


- Har group ke liye, jab tak same character continue ho **aur count 9 se kam ho**, count badhao
- `count < 9` condition ki wajah se **max 9 tak hi** ek chunk me le sakte ho, uske baad naya chunk start hoga (chahe character same ho)
- Har chunk ke baad, `count` aur `character` ko result me append karo
- Ye normal string compression jaisa hi hai bas **9 ki hard limit** ke saath

---

## Complexity

| | |
|---|---|
| Time | O(n) |
| Space | O(n) |

---

## Solution

```cpp
class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int n = word.size();
        int i = 0;

        while (i < n) {
            char currentChar = word[i];
            int count = 0;

            while (i < n && word[i] == currentChar && count < 9) {
                i++;
                count++;
            }

            comp += to_string(count);
            comp += currentChar;
        }

        return comp;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/string-compression-iii/)
