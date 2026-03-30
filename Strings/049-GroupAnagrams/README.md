<div align="center">

# 049. Group Anagrams

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Strings-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-HashMap_+_Sorting-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Strings ka array diya hai — anagrams ko group karo.  
Answer kisi bhi order mein return kar sakte ho.

---

## Examples

| Input | Output |
|-------|--------|
| `["eat","tea","tan","ate","nat","bat"]` | `[["bat"],["nat","tan"],["ate","eat","tea"]]` |
| `[""]` | `[[""]]` |
| `["a"]` | `[["a"]]` |

---

## Approach — HashMap + Sorting

```
strs = ["eat", "tea", "tan", "ate", "nat", "bat"]

Har word ko sort karo → use key banao:

"eat" → sort → "aet"  } 
"tea" → sort → "aet"  }  same key → ek group
"ate" → sort → "aet"  }

"tan" → sort → "ant"  }
"nat" → sort → "ant"  }  same key → ek group

"bat" → sort → "abt"     alag key → alag group

HashMap:
"aet" → ["eat", "tea", "ate"]
"ant" → ["tan", "nat"]
"abt" → ["bat"]

Result: [["eat","tea","ate"], ["tan","nat"], ["bat"]] ✓
```

- Anagram words ko sort karne par **same string** milti hai
- Us sorted string ko **HashMap key** banao
- Sab values collect karke result mein daalo

---

## Complexity

| | |
|---|---|
| Time | O(n × k log k) |
| Space | O(n × k) |

> n = number of strings, k = max string length

---

## Solution

```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagram;
        vector<vector<string>> result;

        for (string word : strs) {
            string temp = word;
            sort(temp.begin(), temp.end());
            anagram[temp].push_back(word);
        }

        for (auto& it : anagram) {
            result.push_back(it.second);
        }

        return result;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/group-anagrams/)