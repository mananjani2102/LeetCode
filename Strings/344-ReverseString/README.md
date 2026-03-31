<div align="center">

# 344. Reverse String

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Strings-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Two_Pointers-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Write a function that reverses a string. Input ek `vector<char>` ke form mein aata hai.  
In-place reverse karo — **O(1) extra memory** use karo.

---

## Examples

| Input | Output |
|-------|--------|
| `['h','e','l','l','o']` | `['o','l','l','e','h']` |
| `['H','a','n','n','a','h']` | `['h','a','n','n','a','H']` |

---

## Approach — Two Pointers

```
s = ['h', 'e', 'l', 'l', 'o']
      ↑                   ↑
    left               right

Step 1: swap(h, o) → ['o', 'e', 'l', 'l', 'h']
Step 2: swap(e, l) → ['o', 'l', 'l', 'e', 'h']
Step 3: left >= right → STOP ✓
```

- `left` pointer start se, `right` pointer end se
- Dono ko swap karo aur beech mein aane tak badhate raho
- Extra array ki zarurat nahi — in-place swap karo

---

## Complexity

| | |
|---|---|
| Time | O(n) |
| Space | O(1) |

---

## Solution

```cpp
// LeetCode 344 - Reverse String
// Approach: Two Pointers
// Time: O(n) | Space: O(1)

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/reverse-string/)