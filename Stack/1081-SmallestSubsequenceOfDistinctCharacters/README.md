<div align="center">

# 1081. Smallest Subsequence of Distinct Characters

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Stack-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Monotonic_Stack-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given string s, return lexicographically smallest subsequence containing all distinct characters of s exactly once.

---

## Examples

| Input | Output |
|-------|--------|
| "bcabc" | "abc" |
| "cbacdcbc" | "acdb" |

---

## Approach - Monotonic Stack + Last Occurrence Tracking

s = "bcabc"

last occurrence: b=3, c=4, a=2

i=0,'b': stack empty → push 'b' → stack=[b]
i=1,'c': top='b'<'c' → push 'c' → stack=[b,c]
i=2,'a': top='c'>'a' and last[c]=4>2 → pop c
top='b'>'a' and last[b]=3>2 → pop b
push 'a' → stack=[a]
i=3,'b': not visited, push → stack=[a,b]
i=4,'c': not visited, push → stack=[a,b,c]

Result = "abc" ✓


- Har character ka **last occurrence index** precompute karo
- Ek **monotonic increasing stack** maintain karo characters ke liye
- Naya character `ch` ke liye: agar `ch` pehle se stack me hai (visited) to skip karo
- Warna, jab tak stack ka top `ch` se bada hai **aur** us top character ka last occurrence abhi bhi aage hai (dobara mil sakta hai), pop karte raho
- Fir current character push karo
- Ye greedy approach smallest lexicographic order ensure karta hai jab tak sabhi characters include ho

**Note:** Ye LeetCode 316 (Remove Duplicate Letters) jaisa hi hai.

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
    string smallestSubsequence(string s) {

        vector<int> last(26);

        for(int i = 0; i < s.size(); i++)
        {
            last[s[i] - 'a'] = i;
        }

        stack<char> st;
        vector<bool> visited(26, false);

        for(int i = 0; i < s.size(); i++)
        {
            char ch = s[i];

            if(visited[ch - 'a'])
                continue;

            while(!st.empty() &&
                  st.top() > ch &&
                  last[st.top() - 'a'] > i)
            {
                visited[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(ch);
            visited[ch - 'a'] = true;
        }

        string ans = "";

        while(!st.empty())
        {
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

[LeetCode Problem](https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/)
