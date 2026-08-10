<div align="center">

# 203. Remove Linked List Elements

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-LinkedList-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Dummy_Node-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given head of linked list and integer val, remove all nodes with Node.val == val, return new head.

---

## Examples

| Input | Output |
|-------|--------|
| head=[1,2,6,3,4,5,6], val=6 | [1,2,3,4,5] |
| head=[], val=1 | [] |
| head=[7,7,7,7], val=7 | [] |

---

## Approach - Dummy Node Skip Matching

list = 1->2->6->3->4->5->6 val=6

dummy->1->2->6->3->4->5->6
prev=dummy, curr=1

curr=1: 1!=6 → prev=1, curr=2
curr=2: 2!=6 → prev=2, curr=6
curr=6: 6==6! → prev.next=curr.next(3) → 2->3, curr=6(old, moves next)
curr=3: 3!=6 → prev=3, curr=4
curr=4: 4!=6 → prev=4, curr=5
curr=5: 5!=6 → prev=5, curr=6
curr=6: 6==6! → prev.next=curr.next(null) → 5->null

Result: 1->2->3->4->5 ✓


- **Dummy node** use karo taaki head bhi delete ho sake to handle ho jaye (jaise agar sabhi nodes matching value ke hon)
- `prev` aur `curr` pointers se traverse karo
- Agar `curr->val == val`, to `prev->next` ko `curr->next` pe point karo (curr node skip ho gaya)
- Warna `prev` ko `curr` pe move karo (normal advance)
- Dono cases me `curr` ko aage badhao

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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;
        ListNode* curr = head;

        while (curr) {
            if (curr->val == val) {
                prev->next = curr->next;
            } else {
                prev = curr;
            }
            curr = curr->next;
        }

        return dummy.next;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/remove-linked-list-elements/)
