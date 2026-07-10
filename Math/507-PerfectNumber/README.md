<div align="center">

# 507. Perfect Number

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Math-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Divisor_Pairs-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given integer num, return true if it is a perfect number (equal to sum of its positive divisors excluding itself).

---

## Examples

| Input | Output |
|-------|--------|
| 28 | true |
| 7 | false |

---

## Approach - Divisor Pairs (sqrt optimization)
num = 28
sum starts at 1 (1 is always a divisor)
i=2: 28%2==0 → sum+=2(=3), sum+=28/2=14(=17)
i=3: 28%3!=0 → skip
i=4: 28%4==0 → sum+=4(=21), sum+=28/4=7(=28)
i=5(sqrt(28)~5.3): 28%5!=0 → skip
sum = 1+2+14+4+7 = 28 == num ✓ → true

- Sirf `sqrt(num)` tak loop chalao — har divisor `i` ka pair `num/i` bhi divisor hota hai
- `1` hamesha divisor hota hai, isliye `sum = 1` se start karo
- Perfect square avoid karo double add hone se (`i != num/i` check)
- End me `sum == num` check karo

---

## Complexity

| | |
|---|---|
| Time | O(sqrt(n)) |
| Space | O(1) |

---

## Solution

```cpp
class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 1) return false;

        int sum = 1;

        for (int i = 2; i <= sqrt(num); i++) {
            if (num % i == 0) {
                sum += i;
                if (i != num / i) {
                    sum += num / i;
                }
            }
        }

        return sum == num;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/perfect-number/)
