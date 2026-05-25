<div align="center">

# 394. Decode String

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Stack-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Two_Stacks-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given an encoded string with format k[encoded_string], return its decoded string where encoded_string repeats exactly k times.

---

## Examples

| Input | Output |
|-------|--------|
| "3[a]2[bc]" | "aaabcbc" |
| "3[a2[c]]" | "accaccacc" |
| "2[abc]3[cd]ef" | "abcabccdcdcdef" |

---

## Approach - Two Stacks

Number stack me multiplier store karo aur string stack me previous string store karo. Digit mile to currNum build karo. [ mile to currNum aur currStr ko push karo, reset karo. ] mile to top se number aur string pop karo, currStr ko repeat karke prevStr ke saath jodo.

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
    string decodeString(string s) {
        stack<int> numStack;
        stack<string> strStack;
        string currStr = "";
        int currNum = 0;
        for(char ch : s) {
            if(isdigit(ch)) {
                currNum = currNum * 10 + (ch - '0');
            }
            else if(ch == '[') {
                numStack.push(currNum);
                strStack.push(currStr);
                currNum = 0;
                currStr = "";
            }
            else if(ch == ']') {
                int repeat = numStack.top();
                numStack.pop();
                string prevStr = strStack.top();
                strStack.pop();
                string temp = "";
                for(int i = 0; i < repeat; i++) {
                    temp += currStr;
                }
                currStr = prevStr + temp;
            }
            else {
                currStr += ch;
            }
        }
        return currStr;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/decode-string/)
