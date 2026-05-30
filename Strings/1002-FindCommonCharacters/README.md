<div align="center">

# 1002. Find Common Characters

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Strings-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Frequency_Array-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given a string array words, return all characters that show up in all strings (including duplicates).

---

## Examples

| Input | Output |
|-------|--------|
| ["bella","label","roller"] | ["e","l","l"] |
| ["cool","lock","cook"] | ["c","o"] |

---

## Approach - Frequency Array + Min Comparison

Common array ko INT_MAX se initialize karo. Har word ke liye uska frequency array banao. Fir har character ke liye common[i] = min(common[i], freq[i]) update karo - isse sirf wahi minimum count bachta hai jo sabhi words me common hai. End me common array se result string array banao.

---

## Complexity

| | |
|---|---|
| Time | O(n × m) where n = words count, m = avg word length |
| Space | O(1) fixed 26 size arrays |

---

## Solution

```cpp
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> common(26, INT_MAX);

        for (string &word : words) {
            vector<int> freq(26, 0);

            for (char ch : word) {
                freq[ch - 'a']++;
            }

            for (int i = 0; i < 26; i++) {
                common[i] = min(common[i], freq[i]);
            }
        }

        vector<string> result;

        for (int i = 0; i < 26; i++) {
            while (common[i] > 0) {
                result.push_back(string(1, 'a' + i));
                common[i]--;
            }
        }

        return result;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/find-common-characters/)
