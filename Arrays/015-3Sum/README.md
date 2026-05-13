<div align="center">

# 15. 3Sum

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Arrays-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Sort_Two_Pointers-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given an integer array `nums`, return all **triplets** `[nums[i], nums[j], nums[k]]` such that `i != j`, `i != k`, `j != k` and their sum equals **0**. Duplicate triplets allowed nahi.

---

## Examples

| Input | Output |
|-------|--------|
| [-1,0,1,2,-1,-4] | [[-1,-1,2],[-1,0,1]] |
| [0,1,1] | [] |
| [0,0,0] | [[0,0,0]] |

---

## Approach — Sort + Two Pointers
nums = [-1,0,1,2,-1,-4]

Sort karo → [-4,-1,-1,0,1,2]
i=0 (-4): left=1, right=5

sum = -4+(-1)+2 = -3 → left++

sum = -4+(-1)+2 ... continue tak right--/left++

No triplet found for i=0
i=1 (-1): left=2, right=5

sum = -1+(-1)+2 = 0 ✓ → [-1,-1,2]

left++, right--

sum = -1+0+1 = 0 ✓ → [-1,0,1]
Duplicate i skip karo (nums[i]==nums[i-1])

- Array ko **sort** karo
- Fix karo ek element `i`, baaki do ko **two pointers** (`left`, `right`) se dhundo
- `sum == 0` → triplet add karo, duplicates skip karo
- `sum < 0` → `left++`, `sum > 0` → `right--`
- Duplicate `i` bhi skip karo

---

## Complexity

| | |
|---|---|
| Time | O(n²) |
| Space | O(1) (sorting ke alawa) |

---

## Solution

```cpp
// LeetCode 15 - 3Sum
// Approach: Sort + Two Pointers
// Time: O(n^2) | Space: O(1)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});

                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;

                    left++;
                    right--;
                }
                else if (sum < 0) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }

        return result;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/3sum/)
