<div align="center">

# 1047. Remove All Adjacent Duplicates In String

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Stack-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Stack-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Repeatedly remove two adjacent equal letters from string s until no more removals are possible. Return the final string.

---

## Examples

| Input | Output |
|-------|--------|
| "abbaca" | "ca" |
| "azxxzy" | "ay" |

---

## Approach - Stack

Har character ke liye check karo agar stack ka top current character ke equal hai. Agar haan, pop karo (duplicate remove). Agar nahi, push karo. End me stack reverse order me result hota hai, isliye usse reverse karke final answer banao.

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
    string removeDuplicates(string s) {
        stack<char> st;
        for(char ch : s) {
            if(!st.empty() && st.top() == ch) {
                st.pop();
            }
            else {
                st.push(ch);
            }
        }
        string ans = "";
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/)
