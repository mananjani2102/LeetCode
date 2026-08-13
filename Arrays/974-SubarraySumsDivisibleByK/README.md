<div align="center">

# 974. Subarray Sums Divisible by K

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Arrays-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Prefix_Sum_HashMap-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given integer array nums and integer k, return count of non-empty subarrays whose sum is divisible by k.

---

## Examples

| Input | Output |
|-------|--------|
| nums=[4,5,0,-2,-3,1], k=5 | 7 |
| nums=[5], k=9 | 0 |

---

## Approach - Prefix Sum HashMap of Remainders

nums = [4,5,0,-2,-3,1] k=5

remainderCount = {0:1}
prefixSum=0, count=0

num=4: prefixSum=4, rem=4%5=4 → count+=0(none), remainderCount[4]=1
num=5: prefixSum=9, rem=9%5=4 → count+=1(from rem4), remainderCount[4]=2
num=0: prefixSum=9, rem=4 → count+=2, remainderCount[4]=3, total count=3
num=-2: prefixSum=7, rem=7%5=2 → count+=0, remainderCount[2]=1, total count=3
num=-3: prefixSum=4, rem=4%5=4 → count+=3(existing rem4), remainderCount[4]=4, total count=6
num=1: prefixSum=5, rem=5%5=0 → count+=1(from rem0 base), remainderCount[0]=2, total count=7

Answer = 7 ✓


- **Key insight**: agar do prefix sums ka **same remainder mod k** hai, to unke beech ka subarray **divisible by k** hoga
- **Prefix sum** calculate karte raho, har step pe uska `remainder mod k` nikalo
- HashMap me har remainder ka **count** track karo
- Agar current remainder pehle bhi `x` baar aa chuka hai, to `x` naye valid subarrays milte hain (kyunki un sabhi purane positions se current tak ka subarray divisible hoga)
- Negative sums ke liye modulo ko **positive** rakhne ke liye `((rem % k) + k) % k` use karo
- Base case: `remainderCount[0] = 1` (empty prefix, taaki poora subarray bhi count ho agar wo directly divisible ho)

---

## Complexity

| | |
|---|---|
| Time | O(n) |
| Space | O(k) |

---

## Solution

```cpp
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> remainderCount;
        remainderCount[0] = 1;

        int prefixSum = 0;
        int count = 0;

        for (int num : nums) {
            prefixSum += num;
            int remainder = ((prefixSum % k) + k) % k;

            if (remainderCount.count(remainder)) {
                count += remainderCount[remainder];
            }

            remainderCount[remainder]++;
        }

        return count;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/subarray-sums-divisible-by-k/)
