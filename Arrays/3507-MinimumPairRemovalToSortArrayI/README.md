<div align="center">

# 3507. Minimum Pair Removal to Sort Array I

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Arrays-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Simulation-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given array nums, repeatedly select adjacent pair with minimum sum (leftmost if tie), replace with their sum. Return minimum operations to make array non-decreasing.

---

## Examples

| Input | Output |
|-------|--------|
| [5,2,3,1] | 2 |
| [1,2,2] | 0 |

---

## Approach - Simulation

nums = [5,2,3,1]

Check non-decreasing? No (5>2)

Find min adjacent pair sum:
(5,2)=7, (2,3)=5, (3,1)=4 → min is (3,1) at index 2

Merge: nums = [5,2,4]
operations=1

Check non-decreasing? No (5>2)

Find min adjacent pair sum:
(5,2)=7, (2,4)=6 → min is (2,4) at index 1

Merge: nums = [5,6]
operations=2

Check non-decreasing? Yes (5<=6) → stop

Answer = 2 ✓


- Har iteration me, sabse pehle check karo array **non-decreasing** hai ya nahi
- Agar nahi hai, **leftmost minimum-sum adjacent pair** dhundo
- Us pair ko unke **sum** se replace karo (array se ek element kam ho jata hai)
- Ye process repeat karo jab tak array sorted na ho jaye
- Simple **brute force simulation** hai, small constraints (`n<=50`) ke liye kaafi hai

---

## Complexity

| | |
|---|---|
| Time | O(n³) worst case |
| Space | O(n) |

---

## Solution

```cpp
class Solution {
public:
    bool isNonDecreasing(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) return false;
        }
        return true;
    }

    int minimumPairRemoval(vector<int>& nums) {
        int operations = 0;

        while (!isNonDecreasing(nums)) {
            int minSum = INT_MAX;
            int minIdx = -1;

            for (int i = 0; i < nums.size() - 1; i++) {
                int sum = nums[i] + nums[i + 1];
                if (sum < minSum) {
                    minSum = sum;
                    minIdx = i;
                }
            }

            nums[minIdx] = nums[minIdx] + nums[minIdx + 1];
            nums.erase(nums.begin() + minIdx + 1);

            operations++;
        }

        return operations;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/minimum-pair-removal-to-sort-array-i/)
