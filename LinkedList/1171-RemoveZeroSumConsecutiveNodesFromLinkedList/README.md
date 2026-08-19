<div align="center">

# 1171. Remove Zero Sum Consecutive Nodes from Linked List

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Linked_List-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Prefix_Sum_HashMap-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given head of a linked list, repeatedly delete consecutive sequences of nodes that sum to 0, until no such sequence exists. Return the head of the final list.

---

## Examples

| Input | Output |
|-------|--------|
| [1,2,-3,3,1] | [3,1] |
| [1,2,3,-3,4] | [1,2,4] |
| [1,2,3,-3,-2] | [1] |

---

## Approach - Prefix Sum HashMap
head = [1,2,3,-3,-2], dummy(0)->1->2->3->-3->-2

Pass 1 (build prefixSum → lastNode map):
dummy(0):   sum=0   → lastNodeWithSum[0]=dummy
1:          sum=1   → lastNodeWithSum[1]=node(1)
2:          sum=3   → lastNodeWithSum[3]=node(2)
3:          sum=6   → lastNodeWithSum[6]=node(3)
-3:         sum=3   → lastNodeWithSum[3]=node(-3)   (overwrites node(2)'s entry)
-2:         sum=1   → lastNodeWithSum[1]=node(-2)   (overwrites node(1)'s entry)

Pass 2 (relink using final map, each sum's LAST occurrence wins):
dummy: sum=0 → dummy->next = lastNodeWithSum[0]->next = dummy->next (still 1) → curr=node(1)
node(1): sum=1 → node(1)->next = lastNodeWithSum[1]->next = node(-2)->next = null
                → curr = null → loop ends

Final list: dummy->1->null → [1] ✓


- **Pass 1**: dummy node (val=0) se shuru karke running `prefixSum` calculate karo, aur har sum ke liye `lastNodeWithSum[sum] = curr` store karo — agar wahi sum dobara aaye to purana overwrite ho jata hai, isliye map me hamesha **us sum wala aakhri node** hi bacha rehta hai
- Yahi trick kaam karti hai: agar do positions pe same prefix sum hai, to unke beech ke saare nodes ka sum **zero** hai — unhe hata dena hai
- **Pass 2**: dobara traverse karo, phir se prefixSum calculate karte hue, aur `curr->next` ko `lastNodeWithSum[prefixSum]->next` se relink kar do — isse beech ke zero-sum segments **skip** ho jaate hai
- Do passes zaroori hai kyunki pehle **poora map final state me** banna chahiye (saare overwrites ho jaane chahiye) tabhi dusre pass me sahi relinking ho paati hai

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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        unordered_map<int, ListNode*> lastNodeWithSum;
        int prefixSum = 0;

        ListNode* curr = dummy;
        while (curr) {
            prefixSum += curr->val;
            lastNodeWithSum[prefixSum] = curr;
            curr = curr->next;
        }

        prefixSum = 0;
        curr = dummy;
        while (curr) {
            prefixSum += curr->val;
            curr->next = lastNodeWithSum[prefixSum]->next;
            curr = curr->next;
        }

        return dummy->next;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/)
