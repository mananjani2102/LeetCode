<div align="center">

# 67. Add Binary

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Strings-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Bit_Addition_with_Carry-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given two binary strings a and b, return their sum as a binary string.

---

## Examples

| Input | Output |
|-------|--------|
| a="11", b="1" | "100" |
| a="1010", b="1011" | "10101" |

---

## Approach - Bit by Bit Addition with Carry
a = "11"   b = "1"
i=1, j=0, carry=0
sum = 0 + 1 + 1 = 2 → ans="0", carry=1
i=0, j=-1, carry=1
sum = 1 + 1 = 2 → ans="00", carry=1
i=-1, j=-1, carry=1
sum = 1 → ans="001", carry=0
reverse → "100" ✓

- Dono strings ke end se start karo (i, j pointers)
- Har step pe dono ke bits aur carry add karo
- `sum % 2` current bit hai, `sum / 2` naya carry hai
- Result reverse karo kyunki end se build kiya tha

---

## Complexity

| | |
|---|---|
| Time | O(max(n, m)) |
| Space | O(max(n, m)) |

---

## Solution

```cpp
class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        string ans = "";

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;

            if (i >= 0)
                sum += a[i--] - '0';

            if (j >= 0)
                sum += b[j--] - '0';

            ans += (sum % 2) + '0';
            carry = sum / 2;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/add-binary/)
