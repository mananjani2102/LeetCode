<div align="center">

# 412. Fizz Buzz

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Math-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Modulo_Check-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given integer n, return string array where multiples of 3 → "Fizz", multiples of 5 → "Buzz", multiples of both → "FizzBuzz", otherwise the number itself.

---

## Examples

| Input | Output |
|-------|--------|
| 3 | ["1","2","Fizz"] |
| 5 | ["1","2","Fizz","4","Buzz"] |
| 15 | ["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"] |

---

## Approach - Modulo Check
i=15: 15%3==0 && 15%5==0 → "FizzBuzz"
i=3:  3%3==0 → "Fizz"
i=5:  5%5==0 → "Buzz"
i=7:  neither → "7"

- 1 se `n` tak loop chalao
- **Pehle** dono se divisible check karo (3 aur 5) → "FizzBuzz"
- Fir sirf 3 se divisible → "Fizz"
- Fir sirf 5 se divisible → "Buzz"
- Koi bhi nahi → number ko string me convert karo

---

## Complexity

| | |
|---|---|
| Time | O(n) |
| Space | O(1) extra (excluding output array) |

---

## Solution

```cpp
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;

        for (int i = 1; i <= n; i++) {
            if (i % 3 == 0 && i % 5 == 0) {
                ans.push_back("FizzBuzz");
            }
            else if (i % 3 == 0) {
                ans.push_back("Fizz");
            }
            else if (i % 5 == 0) {
                ans.push_back("Buzz");
            }
            else {
                ans.push_back(to_string(i));
            }
        }

        return ans;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/fizz-buzz/)
