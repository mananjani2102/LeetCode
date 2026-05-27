<div align="center">

# 438. Find All Anagrams in a String

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Strings-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Sliding_Window-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given two strings s and p, return all start indices of p's anagrams in s.

---

## Examples

| Input | Output |
|-------|--------|
| s="cbaebabacd", p="abc" | [0,6] |
| s="abab", p="ab" | [0,1,2] |

---

## Approach - Sliding Window + Frequency Array

p ka frequency array banao. s me first window (p ki length jitni) ka frequency array banao aur compare karo. Fir window ko slide karo - naya character add karo aur purana character remove karo, har step pe frequency arrays compare karo. Match hone par start index store karo.

---

## Complexity

| | |
|---|---|
| Time | O(n) |
| Space | O(1) fixed 26 size arrays |

---

## Solution

```cpp
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;

        int n = s.size();
        int m = p.size();

        if (m > n) return ans;

        vector<int> pFreq(26, 0);
        vector<int> windowFreq(26, 0);

        for (char c : p) {
            pFreq[c - 'a']++;
        }

        for (int i = 0; i < m; i++) {
            windowFreq[s[i] - 'a']++;
        }

        if (windowFreq == pFreq) {
            ans.push_back(0);
        }

        for (int i = m; i < n; i++) {
            windowFreq[s[i] - 'a']++;          
            windowFreq[s[i - m] - 'a']--;      

            if (windowFreq == pFreq) {
                ans.push_back(i - m + 1);
            }
        }

        return ans;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/find-all-anagrams-in-a-string/)
