<div align="center">

# 3513. Number of Unique XOR Triplets I

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Math-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Bit_Pattern_Next_Power_2-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given nums (permutation of 1 to n), find number of unique values of nums[i] XOR nums[j] XOR nums[k] for i<=j<=k.

---

## Examples

| Input | Output |
|-------|--------|
| [1,2] | 2 |
| [3,1,2] | 4 |

---

## Approach - Bit Pattern Observation (Next Power of 2)

n=2: special case → answer = n = 2

n=3: highestBit = position after highest set bit of 3(=11b)
= 2, answer = 1<<2 = 4 ✓

n=4: highestBit for 4(=100b) = 3, answer = 1<<3 = 8


- Since `i<=j<=k` allows repeated indices, values effectively can repeat — this becomes "pick any 3 values from 1..n with repetition, XOR them"
- Key insight: for `n<=2`, the answer is simply `n` (special small cases)
- For `n>2`, the achievable unique XOR values always form a **complete range from 0 to (next power of 2 - 1)** — because with values up to n you can construct any XOR result within that bit-width using three numbers
- `highestBit` uses `__builtin_clz` to find how many bits `n` needs, then `1 << highestBit` gives the **smallest power of 2 strictly greater than n**
- This matches the mathematical pattern verified against the given examples

---

## Complexity

| | |
|---|---|
| Time | O(1) |
| Space | O(1) |

---

## Solution

```cpp
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        if (n <= 2) return n;

        int highestBit = 32 - __builtin_clz(n);
        return 1 << highestBit;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/number-of-unique-xor-triplets-i/)
