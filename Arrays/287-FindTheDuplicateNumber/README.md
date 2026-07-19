<div align="center">

# 287. Find the Duplicate Number

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Arrays-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Floyd_Cycle_Detection-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given array of n+1 integers where each is in range [1,n], find the one duplicate number. Must not modify array, use O(1) extra space, and solve in linear time.

---

## Examples

| Input | Output |
|-------|--------|
| [1,3,4,2,2] | 2 |
| [3,1,3,4,2] | 3 |
| [3,3,3,3,3] | 3 |

---

## Approach - Floyd's Cycle Detection (treating array as linked list)

nums = [1,3,4,2,2]

Treat as linked list: index → value = "next pointer"
0→1→3→2→4→2 (cycle starts at 2, since 2 appears twice)

Phase 1 - Find meeting point:
slow=nums[0]=1, fast=nums[0]=1
slow=nums[1]=3, fast=nums[nums[1]]=nums[3]=2
slow=nums[3]=2, fast=nums[nums[2]]=nums[4]=2
slow==fast=2 → meeting point found

Phase 2 - Find cycle start (the duplicate):
slow2=nums[0]=1
slow=2, slow2=1 → not equal
slow=nums[2]=4, slow2=nums[1]=3 → not equal
slow=nums[4]=2, slow2=nums[3]=2 → equal!

Duplicate = 2 ✓


- Array ko ek **implicit linked list** ki tarah treat karo — `nums[i]` batata hai next index kya hai
- Kyunki duplicate number hai, kam se kam do indices same value pe point karenge — isse **cycle** ban jati hai
- **Floyd's algorithm** (jaise Linked List Cycle II me) use karo: pehle slow/fast se **meeting point** dhundo, fir dusra pointer start se chala kar **cycle ka entry point** (jo duplicate number hai) nikalo
- Array modify nahi hota, O(1) extra space use hota hai

**Proof of duplicate existence:** Pigeonhole principle — n+1 numbers hain lekin sirf n possible values [1,n], isliye kam se kam ek value repeat hogi.

---

## Complexity

| | |
|---|---|
| Time | O(n) |
| Space | O(1) |

---

## Solution

```cpp
class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int slow = nums[0];
        int fast = nums[0];

        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        int slow2 = nums[0];

        while (slow != slow2) {
            slow = nums[slow];
            slow2 = nums[slow2];
        }

        return slow;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/find-the-duplicate-number/)
