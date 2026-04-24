<div align="center">

# 125. Valid Palindrome

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Strings-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Two_Pointers-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given a string `s`, return `true` if it is a **palindrome** after removing non-alphanumeric characters and converting to lowercase.

---

## Examples

| Input | Output |
|-------|--------|
| "A man, a plan, a canal: Panama" | true |
| "race a car" | false |
| " " | true |

---

## Approach — Two Pointers
s = "A man, a plan, a canal: Panama"
Step 1 - Clean string: "amanaplanacanalpanama"
left=0  right=19 → a == a ✓
left=1  right=18 → m == m ✓
left=2  right=17 → a == a ✓
...
All match → true ✓

- `left` aur `right` do pointer rakho
- Non-alphanumeric characters skip karo
- Lowercase me compare karo
- Sab match ho to `true`

---

## Complexity

| | |
|---|---|
| Time | O(n) |
| Space | O(1) |

---

## Solution

```cpp
// LeetCode 125 - Valid Palindrome
// Approach: Two Pointers
// Time: O(n) | Space: O(1)

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;
        while (left < right) {
            while (left < right && !isalnum(s[left])) left++;
            while (left < right && !isalnum(s[right])) right--;
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/valid-palindrome/)