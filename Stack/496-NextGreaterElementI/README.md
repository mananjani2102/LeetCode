<div align="center">

# 496. Next Greater Element I

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Stack-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Monotonic_Stack-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

For each element in nums1, find its next greater element in nums2 (first greater element to the right). If none exists, answer is -1.

---

## Examples

| Input | Output |
|-------|--------|
| nums1=[4,1,2], nums2=[1,3,4,2] | [-1,3,-1] |
| nums1=[2,4], nums2=[1,2,3,4] | [3,-1] |

---

## Approach - Monotonic Stack + HashMap

nums2 ko right se left traverse karo. Stack maintain karo jisme elements decreasing order me rahein (monotonic stack). Har element ke liye stack se chote ya equal elements pop karo jab tak top current element se bada na ho - wahi answer hai. HashMap me result store karo, fir nums1 ke har element ka answer map se nikal lo.

---

## Complexity

| | |
|---|---|
| Time | O(n + m) |
| Space | O(n) |

---

## Solution

```cpp
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> mp;

        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }
            if (st.empty()) {
                mp[nums2[i]] = -1;
            } else {
                mp[nums2[i]] = st.top();
            }
            st.push(nums2[i]);
        }
        vector<int> ans;
        for (int num : nums1) {
            ans.push_back(mp[num]);
        }
        return ans;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/next-greater-element-i/)
