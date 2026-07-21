<div align="center">

# 1456. Maximum Number of Vowels in a Substring of Given Length

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Strings-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Sliding_Window-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given string s and integer k, return the maximum number of vowel letters in any substring of s with length k.

---

## Examples

| Input | Output |
|-------|--------|
| s="abciiidef", k=3 | 3 |
| s="aeiou", k=2 | 2 |
| s="leetcode", k=3 | 2 |

---

## Approach - Sliding Window

s = "abciiidef" k=3

First window [0,3) = "abc": vowels='a' → count=1, ans=1

Slide window:
i=3: remove s[0]='a'(vowel,count--=0), add s[3]='i'(vowel,count++=1) → ans=1
i=4: remove s[1]='b'(no), add s[4]='i'(vowel,count++=2) → ans=2
i=5: remove s[2]='c'(no), add s[5]='i'(vowel,count++=3) → ans=3
i=6: remove s[3]='i'(vowel,count--=2), add s[6]='d'(no) → ans=3 (stays)
...

Answer = 3 ✓


- Pehle **first window** (size k) ke vowels count karo
- Fir window ko **slide** karo: har step pe left se ek character remove karo aur right se naya add karo
- `count` ko sliding window ke basis pe increment/decrement karte raho
- Har step pe `ans` ko max se update karo

---

## Complexity

| | |
|---|---|
| Time | O(n) |
| Space | O(1) |

---

## Solution

```cpp
class Solution {
public:

    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' ||
               ch == 'o' || ch == 'u';
    }

    int maxVowels(string s, int k) {

        int count = 0;

        for (int i = 0; i < k; i++) {
            if (isVowel(s[i])) {
                count++;
            }
        }

        int ans = count;  

        for (int i = k; i < s.size(); i++) {

            if (isVowel(s[i - k])) {
                count--;
            }

            if (isVowel(s[i])) {
                count++;
            }

            ans = max(ans, count);
        }

        return ans;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/)
