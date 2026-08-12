<div align="center">

# 318. Maximum Product of Word Lengths

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Bit_Manipulation-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Bitmask_Comparison-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given string array words, return max length(word[i])*length(word[j]) where the two words share no common letters. Return 0 if no such pair exists.

---

## Examples

| Input | Output |
|-------|--------|
| ["abcw","baz","foo","bar","xtfn","abcdef"] | 16 |
| ["a","ab","abc","d","cd","bcd","abcd"] | 4 |
| ["a","aa","aaa","aaaa"] | 0 |

---

## Approach - Bitmask Comparison

word="abcw" → bitmask: bit for a,b,c,w set → 26-bit number

To check if two words share common letters:
mask1 & mask2 == 0 → no common letters (bits don't overlap)

words = ["abcw","xtfn"]
mask("abcw") has bits for a,b,c,w
mask("xtfn") has bits for x,t,f,n
mask1 & mask2 = 0 → no common letters → valid pair!
product = 4*4 = 16 ✓


- Har word ke liye ek **26-bit bitmask** banao — har character ke liye corresponding bit set karo (`1 << (ch-'a')`)
- Do words me **common letters** check karna ab simple ho jata hai: `mask1 & mask2 == 0` matlab koi common letter nahi hai
- Sabhi pairs `(i,j)` check karo — agar unke masks me overlap nahi hai to unka length product calculate karo
- Maximum product track karo

---

## Complexity

| | |
|---|---|
| Time | O(n² + total_chars) — bitmask banane me O(total_chars), comparison me O(n²) |
| Space | O(n) for masks array |

---

## Solution

```cpp
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> masks(n, 0);

        for (int i = 0; i < n; i++) {
            for (char ch : words[i]) {
                masks[i] |= (1 << (ch - 'a'));
            }
        }

        int maxProd = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if ((masks[i] & masks[j]) == 0) {
                    int product = words[i].size() * words[j].size();
                    maxProd = max(maxProd, product);
                }
            }
        }

        return maxProd;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/maximum-product-of-word-lengths/)
