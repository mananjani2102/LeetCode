<div align="center">

# 16. 3Sum Closest

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Arrays-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Sort_Two_Pointers-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given integer array nums and target, find three integers whose sum is closest to target. Return that sum.

---

## Examples

| Input | Output |
|-------|--------|
| nums=[-1,2,1,-4], target=1 | 2 |
| nums=[0,0,0], target=1 | 0 |

---

## Approach - Sort Two Pointers
nums = [-1,2,1,-4]   target = 1
Sort → [-4,-1,1,2]
i=0(-4): left=1,right=3
sum=-4-1+2=-3 → diff=4, closestSum=-3
sum<target → left++
sum=-4+1+2=-1 → diff=2 < 4 → closestSum=-1
sum<target → left++
left==right, stop
i=1(-1): left=2,right=3
sum=-1+1+2=2 → diff=1 < 2 → closestSum=2
sum>target → right--
left==right, stop
Answer = 2 ✓

- Array ko **sort** karo
- Fix karo ek element `i`, baaki do ko **two pointers** (`left`, `right`) se dhundo
- Har combination ka sum nikal kar `target` se **absolute difference** check karo
- Jo bhi sum sabse chota difference de, use `closestSum` me store karo
- `sum < target` → `left++`, `sum > target` → `right--`
- Agar `sum == target` mile to turant return kar do (perfect match)

---

## Complexity

| | |
|---|---|
| Time | O(n²) |
| Space | O(1) (sorting ke alawa) |

---

## Solution

```cpp
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int closestSum = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n - 2; i++) {
            int left = i + 1, right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (abs(sum - target) < abs(closestSum - target)) {
                    closestSum = sum;
                }

                if (sum == target) {
                    return sum;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        return closestSum;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/3sum-closest/)
