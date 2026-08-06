<div align="center">

# 38. Count and Say

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Strings-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Iterative_RLE-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given n, return nth term of count-and-say sequence, where each term is the run-length encoding of the previous term.

---

## Examples

| Input | Output |
|-------|--------|
| 4 | "1211" |
| 1 | "1" |

---

## Approach - Iterative Run-Length Encoding

n=4

Start: result = "1"

Iteration 1: RLE of "1"
→ one '1' → "11"
result = "11"

Iteration 2: RLE of "11"
→ two '1's → "21"
result = "21"

Iteration 3: RLE of "21"
→ one '2', one '1' → "12" + "11" = "1211"
result = "1211"

Answer = "1211" ✓


- `result` ko `"1"` se start karo (base case)
- `n-1` baar loop chalao — har iteration me current string ka **run-length encoding** banao
- RLE ke liye: consecutive same characters count karo, fir `count + character` next string me append karo
- End me `result` hi answer hai

**Follow-up:** Iterative solution already upar diya hai — koi recursion nahi use kiya.

---

## Complexity

| | |
|---|---|
| Time | O(n × m) where m = length of string at each step |
| Space | O(m) |

---

## Solution

```cpp
class Solution {
public:
    string countAndSay(int n) {
        string result = "1";

        for (int i = 1; i < n; i++) {
            string next = "";
            int j = 0;

            while (j < result.size()) {
                char currentChar = result[j];
                int count = 0;

                while (j < result.size() && result[j] == currentChar) {
                    count++;
                    j++;
                }

                next += to_string(count) + currentChar;
            }

            result = next;
        }

        return result;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/count-and-say/)
