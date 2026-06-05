<div align="center">

# 1209. Remove All Adjacent Duplicates in String II

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Stack-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Two_Pointer_Count_Array-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Repeatedly remove k adjacent equal letters from string s until no more removals are possible. Return the final string.

---

## Examples

| Input | Output |
|-------|--------|
| s="abcd", k=2 | "abcd" |
| s="deeedbbcccbdaa", k=3 | "aa" |
| s="pbbcggttciiippooaais", k=2 | "ps" |

---

## Approach - Two Pointer + Count Array (Stack Simulation)

j pointer use karke s ko in-place build karo. cnt array har position ke consecutive same character count rakhta hai. Agar current character pichle wale (j-1) se match kare to count badhao, warna 1 se reset karo. Jab count k tak pahunch jaye to j ko k peeche kar do (effectively wo characters remove ho gaye). End me s.substr(0, j) hi final answer hai.

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
    string removeDuplicates(string s, int k) {
        int n = s.size();
        vector<int> cnt(n);

        int j = 0;

        for (int i = 0; i < n; ++i, ++j) {
            s[j] = s[i];

            cnt[j] = (j > 0 && s[j] == s[j - 1])
                     ? cnt[j - 1] + 1
                     : 1;

            if (cnt[j] == k)
                j -= k;
        }

        return s.substr(0, j);
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/)
