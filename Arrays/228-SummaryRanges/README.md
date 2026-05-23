<div align="center">

# 228. Summary Ranges

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Arrays-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Linear_Scan-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given a **sorted unique** integer array `nums`, return the smallest list of **ranges** that exactly cover all numbers — formatted as `"a->b"` or `"a"`.

---

## Examples

| Input | Output |
|-------|--------|
| [0,1,2,4,5,7] | ["0->2","4->5","7"] |
| [0,2,3,4,6,8,9] | ["0","2->4","6","8->9"] |

---

## Approach — Linear Scan
nums = [0,1,2,4,5,7]
i=0: start=0

nums[1]=1=0+1 → i=1

nums[2]=2=1+1 → i=2

nums[3]=4≠2+1 → stop

end=2 → "0->2"
i=3: start=4

nums[4]=5=4+1 → i=4

nums[5]=7≠5+1 → stop

end=5 → "4->5"
i=5: start=7, end=7 → "7"
Result = ["0->2","4->5","7"] ✓

- Har index pe **start** mark karo
- Jab tak consecutive numbers (`nums[i+1] == nums[i]+1`) milte rahein, aage badho
- Range khatam ho to `start == end` check karo aur format karo
- `"a->b"` ya `"a"` push karo result me

---

## Complexity

| | |
|---|---|
| Time | O(n) |
| Space | O(1) extra |

---

## Solution

```cpp
// LeetCode 228 - Summary Ranges
// Approach: Linear Scan
// Time: O(n) | Space: O(1) extra

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int start = nums[i];

            while (i + 1 < n && nums[i + 1] == nums[i] + 1) {
                i++;
            }

            int end = nums[i];

            if (start == end) {
                ans.push_back(to_string(start));
            } else {
                ans.push_back(to_string(start) + "->" + to_string(end));
            }
        }

        return ans;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/summary-ranges/)
