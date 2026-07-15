<div align="center">

# 18. 4Sum

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Arrays-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Sort_Two_Pointers-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given array nums and target, return all unique quadruplets [nums[a],nums[b],nums[c],nums[d]] whose sum equals target.

---

## Examples

| Input | Output |
|-------|--------|
| nums=[1,0,-1,0,-2,2], target=0 | [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]] |
| nums=[2,2,2,2,2], target=8 | [[2,2,2,2]] |

---

## Approach - Sort Two Pointers (Extension of 3Sum)
nums = [1,0,-1,0,-2,2]   target=0
Sort → [-2,-1,0,0,1,2]
i=0(-2), j=1(-1): left=2,right=5
sum=-2-1+0+2=-1 → left++
sum=-2-1+0+2 wait recalc: left=3(0),right=5(2): -2-1+0+2=-1 → left++
left=4(1),right=5(2): -2-1+1+2=0 ✓ → [-2,-1,1,2]
i=0(-2), j=2(0): left=3,right=5
sum=-2+0+0+2=0 ✓ → [-2,0,0,2]
i=1(-1), j=2(0): left=3,right=5
sum=-1+0+0+2=1... adjusting: -1+0+0+1=0 ✓ → [-1,0,0,1]
Result: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]] ✓

- Ye **3Sum** ka extension hai — ek extra loop add karo
- Array ko **sort** karo, fir do fixed indices `i, j` choose karo aur baaki do (`left, right`) ko **two pointers** se dhundo
- Har level pe **duplicates skip** karo (`nums[i]==nums[i-1]`, `nums[j]==nums[j-1]`)
- `sum == target` → quadruplet add karo aur duplicate `left, right` skip karo
- `sum < target` → `left++`, `sum > target` → `right--`
- Overflow bachane ke liye sum ko `long long` me calculate karo (values 10^9 tak ho sakti hain)

---

## Complexity

| | |
|---|---|
| Time | O(n³) |
| Space | O(1) excluding output |

---

## Solution

```cpp
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int left = j + 1, right = n - 1;

                while (left < right) {
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                    if (sum == target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});

                        while (left < right && nums[left] == nums[left + 1]) left++;
                        while (left < right && nums[right] == nums[right - 1]) right--;

                        left++;
                        right--;
                    }
                    else if (sum < target) {
                        left++;
                    }
                    else {
                        right--;
                    }
                }
            }
        }

        return result;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/4sum/)
