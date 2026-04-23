<div align="center">

# 3. Longest Substring Without Repeating Characters

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Strings-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Sliding_Window-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given a string `s`, find the length of the **longest substring** without duplicate characters.

---

## Examples

| Input | Output |
|-------|--------|
| s = "abcabcbb" | 3 |
| s = "bbbbb" | 1 |
| s = "pwwkew" | 3 |

---

## Approach — Sliding Window

```
s = "abcabcbb"

right=0 → st={a}, maxLen=1
right=1 → st={a,b}, maxLen=2
right=2 → st={a,b,c}, maxLen=3
right=3 → 'a' duplicate! remove s[left]='a', left=1
         → st={b,c,a}, maxLen=3
right=4 → 'b' duplicate! remove s[left]='b', left=2
         → st={c,a,b}, maxLen=3
...
Answer = 3 ✓
```

- `left` aur `right` do pointer rakho
- `right` aage badhta hai
- Duplicate mile to `left` aage karo aur set se remove karo
- Har step pe `maxLen` update karo

---

## Complexity

| | |
|---|---|
| Time | O(n) |
| Space | O(n) |

---

## Solution

```cpp
// LeetCode 3 - Longest Substring Without Repeating Characters
// Approach: Sliding Window
// Time: O(n) | Space: O(n)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int left = 0, maxLen = 0;

        for (int right = 0; right < s.size(); right++) {
            while (st.find(s[right]) != st.end()) {
                st.erase(s[left]);
                left++;
            }
            st.insert(s[right]);
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/longest-substring-without-repeating-characters/)