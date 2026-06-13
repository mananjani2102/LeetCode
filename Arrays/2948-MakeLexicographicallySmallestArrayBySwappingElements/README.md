<div align="center">

# 2948. Make Lexicographically Smallest Array by Swapping Elements

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Arrays-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Sort_Group_Swap-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given array nums and integer limit, swap any two elements if their absolute difference is at most limit, any number of times. Return the lexicographically smallest array possible.

---

## Examples

| Input | Output |
|-------|--------|
| nums=[1,5,3,9,8], limit=2 | [1,3,5,8,9] |
| nums=[1,7,6,18,2,1], limit=3 | [1,6,7,18,1,2] |
| nums=[1,7,28,19,10], limit=3 | [1,7,28,19,10] |

---

## Approach - Sort Group Swap

Values aur unke original indices ko pair karke sort kar do. Sorted array me consecutive elements jinka difference limit se kam ya equal hai, wo ek hi "group" me aate hain (transitively swap kar sakte hain). Har group ke liye, unke original indices ko sort karo aur unme sorted values ko smallest se largest assign karo - isse lexicographically smallest arrangement milta hai.

---

## Complexity

| | |
|---|---|
| Time | O(n log n) |
| Space | O(n) |

---

## Solution

```cpp
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        sort(arr.begin(), arr.end());

        vector<int> ans(n);

        int start = 0;

        while (start < n) {
            int end = start;

            while (end + 1 < n &&
                   arr[end + 1].first - arr[end].first <= limit) {
                end++;
            }

            vector<int> indices;
            vector<int> values;

            for (int i = start; i <= end; i++) {
                indices.push_back(arr[i].second);
                values.push_back(arr[i].first);
            }

            sort(indices.begin(), indices.end());

            for (int i = 0; i < indices.size(); i++) {
                ans[indices[i]] = values[i];
            }

            start = end + 1;
        }

        return ans;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/)
