<div align="center">

# 2942. Find Words Containing Character

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Strings-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Linear_Search-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given array of strings words and character x, return indices of words that contain x.

---

## Examples

| Input | Output |
|-------|--------|
| words=["leet","code"], x='e' | [0,1] |
| words=["abc","bcd","aaaa","cbc"], x='a' | [0,2] |
| words=["abc","bcd","aaaa","cbc"], x='z' | [] |

---

## Approach - Linear Search with find()

Har word ke liye built-in find() function use karo character x dhundne ke liye. Agar find() string::npos return na kare (yaani character mil gaya), to us word ka index result me add kar do. Sabhi words check karne ke baad result return karo.

---

## Complexity

| | |
|---|---|
| Time | O(n × m) where n = words count, m = avg word length |
| Space | O(1) extra |

---

## Solution

```cpp
class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;

        for (int i = 0; i < words.size(); i++) {
            if (words[i].find(x) != string::npos) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/find-words-containing-character/)
