<div align="center">

# 739. Daily Temperatures

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Stack-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Monotonic_Stack-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given daily temperatures array, return answer array such that answer[i] tells how many days you have to wait for a warmer temperature. If none, answer[i] = 0.

---

## Examples

| Input | Output |
|-------|--------|
| [73,74,75,71,69,72,76,73] | [1,1,4,2,1,1,0,0] |
| [30,40,50,60] | [1,1,1,0] |
| [30,60,90] | [1,1,0] |

---

## Approach - Monotonic Stack

Stack me indices store karo jinka temperature abhi tak "answer" nahi mila. Har naye din ke liye, jab tak current temperature stack ke top wale index ke temperature se zyada ho, pop karo aur unka answer calculate karo (current index - stored index). Fir current index ko push kar do stack me.

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
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() &&
                   temperatures[i] > temperatures[st.top()]) {
                int idx = st.top();
                st.pop();
                ans[idx] = i - idx;
            }
            st.push(i);
        }
        return ans;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/daily-temperatures/)
