<div align="center">

# 3129. Find All Possible Stable Binary Arrays I

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Dynamic_Programming-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-3D_DP-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Ek binary array **stable** hoti hai agar:
- Exactly `zero` zeros aur `one` ones ho
- Koi bhi subarray jiska size `limit` se bada ho, usme dono 0 aur 1 hon

Total stable arrays ka count return karo — modulo `10⁹ + 7`.

---

## Examples

| zero | one | limit | Output |
|------|-----|-------|--------|
| 1 | 1 | 2 | 2 |
| 1 | 2 | 1 | 1 |
| 3 | 3 | 2 | 14 |

---

## Approach — 3D Dynamic Programming

```
dp[z][o][last] = kitne tarike hain jab:
  z    = zeros use ho chuke hain
  o    = ones  use ho chuke hain
  last = 0 agar last placed digit 0 tha
         1 agar last placed digit 1 tha

Base Cases:
  dp[i][0][0] = 1  for i = 1..limit  (sirf zeros, limit ke andar)
  dp[0][i][1] = 1  for i = 1..limit  (sirf ones,  limit ke andar)

Transition:
  Agar last=1 tha, ab k zeros place karo (k = 1..limit):
    dp[z+k][o][0] += dp[z][o][1]

  Agar last=0 tha, ab k ones place karo (k = 1..limit):
    dp[z][o+k][1] += dp[z][o][0]

Answer = dp[zero][one][0] + dp[zero][one][1]
```

- Ek saath `k` same digits place karte hain (1 to limit)
- Isse automatically limit constraint enforce ho jaati hai
- Dono endings (0 ya 1) ka sum final answer hai

---

## Complexity

| | |
|---|---|
| Time | O(zero × one × limit) |
| Space | O(zero × one) |

---

## Solution

```cpp
class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        const int MOD = 1000000007;

        vector<vector<vector<long long>>> dp(
            zero + 1,
            vector<vector<long long>>(one + 1, vector<long long>(2, 0))
        );

        for (int i = 1; i <= limit && i <= zero; i++) dp[i][0][0] = 1;
        for (int i = 1; i <= limit && i <= one;  i++) dp[0][i][1] = 1;

        for (int z = 0; z <= zero; z++) {
            for (int o = 0; o <= one; o++) {

                for (int k = 1; k <= limit && z + k <= zero; k++)
                    dp[z + k][o][0] = (dp[z + k][o][0] + dp[z][o][1]) % MOD;

                for (int k = 1; k <= limit && o + k <= one; k++)
                    dp[z][o + k][1] = (dp[z][o + k][1] + dp[z][o][0]) % MOD;
            }
        }

        return (dp[zero][one][0] + dp[zero][one][1]) % MOD;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/find-all-possible-stable-binary-arrays-i/)