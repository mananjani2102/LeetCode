<div align="center">

# 2958. Length of Longest Subarray With at Most K Frequency

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Arrays-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Sliding_Window_HashMap-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given array nums and integer k, find the length of the longest subarray where every element's frequency is at most k.

---

## Examples

| Input | Output |
|-------|--------|
| nums=[1,2,3,1,2,3,1,2], k=2 | 6 |
| nums=[1,2,1,2,1,2,1,2], k=1 | 2 |
| nums=[5,5,5,5,5,5,5], k=4 | 4 |

---

## Approach - Sliding Window with HashMap

nums = [1,2,3,1,2,3,1,2] k=2

right=0: freq[1]=1, window valid, maxLen=1
right=1: freq[2]=1, window valid, maxLen=2
right=2: freq[3]=1, window valid, maxLen=3
right=3: freq[1]=2, window valid, maxLen=4
right=4: freq[2]=2, window valid, maxLen=5
right=5: freq[3]=2, window valid, maxLen=6
right=6: freq[1]=3 > k! shrink: freq[1]--, left++ → freq[1]=2, window valid
maxLen stays 6 (window size now 6)
right=7: freq[2]=3 > k! shrink: freq[nums[left]]--, left++ → freq[2]=2
maxLen stays 6

Answer = 6 ✓


- **Sliding window** technique with HashMap for frequency tracking
- `right` pointer se window expand karo, current element ka frequency increment karo
- Agar current element ka frequency `k` se **exceed** ho jaye, `left` pointer se window **shrink** karo jab tak frequency valid na ho jaye
- Har valid window ke baad, window size (`right-left+1`) se `maxLen` update karo

---

## Complexity

| | |
|---|---|
| Time | O(n) |
| Space | O(n) |

---

## Solution

```cpp
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int left = 0;
        int maxLen = 0;

        for (int right = 0; right < nums.size(); right++) {
            freq[nums[right]]++;

            while (freq[nums[right]] > k) {
                freq[nums[left]]--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/)
