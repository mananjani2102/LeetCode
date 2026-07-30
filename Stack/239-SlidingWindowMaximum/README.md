<div align="center">

# 239. Sliding Window Maximum

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Stack-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Monotonic_Deque-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given array nums and window size k, return the maximum value in each sliding window of size k as it moves from left to right.

---

## Examples

| Input | Output |
|-------|--------|
| nums=[1,3,-1,-3,5,3,6,7], k=3 | [3,3,5,5,6,7] |
| nums=[1], k=1 | [1] |

---

## Approach - Monotonic Deque

nums = [1,3,-1,-3,5,3,6,7] k=3

i=0: dq=0
i=1: nums[0]=1<nums[1]=3 → pop 0, push 1 → dq=1
i=2: nums[1]=3>=nums[2]=-1 → push 2 → dq=[1,2]
i>=k-1(2) → result=[3]
i=3: dq.front()=1, 1<=3-3=0? No. nums[2]=-1<nums[3]=-3? No → push 3 → dq=[1,2,3]
result=[3,3]
i=4: pop front if outdated: dq.front()=1<=4-3=1 → pop 1 → dq=[2,3]
nums[3]=-3<nums[4]=5 → pop 3, nums[2]=-1<5 → pop 2 → dq=[]
push 4 → dq=[4]
result=[3,3,5]
...continues similarly

Final: [3,3,5,5,6,7] ✓


- **Monotonic decreasing deque** maintain karo — deque me indices store karo jinke corresponding values decreasing order me hon
- Har naye element ke liye: pehle **out-of-window** indices ko front se remove karo (`dq.front() <= i-k`)
- Fir jo bhi elements current element se **chote** hain unhe back se pop karo (kyunki wo kabhi max nahi banenge)
- Current index push karo
- Jab window full ho jaye (`i >= k-1`), front element (jo sabse bada hai current window ka) result me add karo

---

## Complexity

| | |
|---|---|
| Time | O(n) — har element ek baar push aur pop hota hai |
| Space | O(k) for deque |

---

## Solution

```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> result;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);

            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }

        return result;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/sliding-window-maximum/)
