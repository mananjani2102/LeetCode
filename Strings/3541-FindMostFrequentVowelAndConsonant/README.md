<div align="center">

# 3541. Find Most Frequent Vowel and Consonant

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Strings-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Frequency_Array-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given string s, find the maximum frequency vowel and maximum frequency consonant separately, return the sum of both frequencies.

---

## Examples

| Input | Output |
|-------|--------|
| "successes" | 6 |
| "aeiaeia" | 3 |

---

## Approach - Frequency Array

26 size ka frequency array banao aur har character ka count store karo. Fir a-z tak loop chalao - check karo character vowel hai (a,e,i,o,u) ya consonant. Vowels me se max frequency aur consonants me se max frequency dono track karo. End me dono ka sum return karo.

---

## Complexity

| | |
|---|---|
| Time | O(n) |
| Space | O(1) fixed 26 size array |

---

## Solution

```cpp
class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> freq(26, 0);

        for (char ch : s) {
            freq[ch - 'a']++;
        }

        int maxVowel = 0, maxConsonant = 0;

        for (int i = 0; i < 26; i++) {
            char ch = 'a' + i;

            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                maxVowel = max(maxVowel, freq[i]);
            } else {
                maxConsonant = max(maxConsonant, freq[i]);
            }
        }

        return maxVowel + maxConsonant;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/find-most-frequent-vowel-and-consonant/)
