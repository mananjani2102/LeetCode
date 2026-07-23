<div align="center">

# 147. Insertion Sort List

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-LinkedList-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Dummy_Node_Insertion-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given head of a linked list, sort it using insertion sort algorithm and return sorted head.

---

## Examples

| Input | Output |
|-------|--------|
| [4,2,1,3] | [1,2,3,4] |
| [-1,5,3,4,0] | [-1,0,3,4,5] |

---

## Approach - Dummy Node + Insert at Correct Position

list = 4->2->1->3

dummy->null
curr=4: prev=dummy(null), insert → dummy->4

curr=2: find position (dummy->4)
prev=dummy, prev.next=4, 4<2? No, stop
insert 2 before 4 → dummy->2->4

curr=1: find position (dummy->2->4)
prev=dummy, prev.next=2, 2<1? No, stop
insert 1 before 2 → dummy->1->2->4

curr=3: find position (dummy->1->2->4)
prev=dummy, prev.next=1, 1<3? Yes, prev=1
prev.next=2, 2<3? Yes, prev=2
prev.next=4, 4<3? No, stop
insert 3 after 2, before 4 → dummy->1->2->3->4

Result: 1->2->3->4 ✓


- **Dummy node** use karo taaki sorted list ka head easily track ho sake
- Original list se ek ek node nikalo (`curr`), aage ka link save karo (`next`)
- Sorted portion me sahi position dhundo (`prev` pointer se traverse karke) — jahan `prev->next->val >= curr->val`
- Us position pe `curr` node insert karo
- Repeat jab tak saari original list process na ho jaye

---

## Complexity

| | |
|---|---|
| Time | O(n²) |
| Space | O(1) |

---

## Solution

```cpp
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(0);

        ListNode* curr = head;

        while (curr) {
            ListNode* next = curr->next;

            ListNode* prev = &dummy;
            while (prev->next && prev->next->val < curr->val) {
                prev = prev->next;
            }

            curr->next = prev->next;
            prev->next = curr;

            curr = next;
        }

        return dummy.next;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/insertion-sort-list/)
