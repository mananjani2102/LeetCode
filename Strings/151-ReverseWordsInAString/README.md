<div align="center">

# 151. Reverse Words in a String

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Strings-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-String_Stream-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given an input string `s`, reverse the order of the **words**. Extra spaces remove karo — sirf ek space ho words ke beech.

---

## Examples

| Input | Output |
|-------|--------|
| "the sky is blue" | "blue is sky the" |
| "  hello world  " | "world hello" |
| "a good   example" | "example good a" |

---

## Approach — String Stream
```
s = "the sky is blue"

Step 1 - Words extract karo:
["the", "sky", "is", "blue"]

Step 2 - Reverse karo:
["blue", "is", "sky", "the"]

Step 3 - Join karo:
"blue is sky the" ✓
```

- `stringstream` se automatically extra spaces remove hote hain
- `reverse()` se words ulte karo
- Loop se single space ke sath join karo

---

## Complexity

| | |
|---|---|
| Time | O(n) |
| Space | O(n) |

---

## Solution
```cpp
// LeetCode 151 - Reverse Words in a String
// Approach: String Stream
// Time: O(n) | Space: O(n)

class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        stringstream ss(s);
        string word;
        while (ss >> word) {
            words.push_back(word);
        }
        reverse(words.begin(), words.end());
        string result = "";
        for (int i = 0; i < words.size(); i++) {
            if (i != 0) result += " ";
            result += words[i];
        }
        return result;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/reverse-words-in-a-string/)