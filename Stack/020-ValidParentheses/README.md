<div align="center">

# 20. Valid Parentheses

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Stack-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Stack-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given a string `s` containing `(`, `)`, `{`, `}`, `[`, `]`, determine if it is **valid** — brackets must close in correct order and type.

---

## Examples

| Input | Output |
|-------|--------|
| "()" | true |
| "()[]{}" | true |
| "(]" | false |
| "([])" | true |
| "([)]" | false |

---

## Approach — Stack

```
s = "([)]"

'(' → push → stack: [(]
'[' → push → stack: [(, []
')' → top is '[' but need '(' → MISMATCH ✗
→ return false
```
s = "([])"
'(' → push → stack: [(]

'[' → push → stack: [(, []

']' → top is '[' matches → pop → stack: [(]

')' → top is '(' matches → pop → stack: []

stack empty → return true ✓

- Opening bracket mile → **push** karo stack me
- Closing bracket mile → stack ka **top** check karo
- Match ho to **pop** karo, warna `false`
- End me stack **empty** ho to `true`

---

## Complexity

| | |
|---|---|
| Time | O(n) |
| Space | O(n) |

---

## Solution

```cpp
// LeetCode 20 - Valid Parentheses
// Approach: Stack
// Time: O(n) | Space: O(n)

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(char c : s) {
            if(c == '(' || c == '{' || c == '[') {
                st.push(c);
            } 
            else {
                if(st.empty()) return false;

                char top = st.top();

                if((c == ')' && top == '(') ||
                   (c == '}' && top == '{') ||
                   (c == ']' && top == '[')) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }

        return st.empty();
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/valid-parentheses/)
