<div align="center">

# 150. Evaluate Reverse Polish Notation

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Stack-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Stack-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given an array of strings `tokens` representing an arithmetic expression in **Reverse Polish Notation**, evaluate and return the integer result.

---

## Examples

| Input | Output |
|-------|--------|
| ["2","1","+","3","*"] | 9 |
| ["4","13","5","/","+"] | 6 |
| ["10","6","9","3","+","-11","*","/","*","17","+","5","+"] | 22 |

---

## Approach — Stack
tokens = ["2","1","+","3","*"]
"2" → push → stack: [2]

"1" → push → stack: [2,1]

"+" → pop b=1, pop a=2 → push(2+1=3) → stack: [3]

"3" → push → stack: [3,3]

"" → pop b=3, pop a=3 → push(33=9) → stack: [9]
Result = 9 ✓

- Number mile to **push** karo stack me
- Operator mile to **2 numbers pop** karo (`b` pehle, `a` baad me)
- Operation apply karo aur result **push** karo
- End me stack ka top hi answer hai

---

## Complexity

| | |
|---|---|
| Time | O(n) |
| Space | O(n) |

---

## Solution

```cpp
// LeetCode 150 - Evaluate Reverse Polish Notation
// Approach: Stack
// Time: O(n) | Space: O(n)

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string token : tokens) {
            if (token == "+" || token == "-" ||
                token == "*" || token == "/") {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                if (token == "+")
                    st.push(a + b);
                else if (token == "-")
                    st.push(a - b);
                else if (token == "*")
                    st.push(a * b);
                else
                    st.push(a / b);
            }
            else {
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/evaluate-reverse-polish-notation/)
