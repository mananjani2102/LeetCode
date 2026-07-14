<div align="center">

# 19. Remove Nth Node From End of List

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-LinkedList-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Two_Pointers_One_Pass-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given head of linked list, remove the nth node from the end and return the head. Follow up: solve in one pass.

---

## Examples

| Input | Output |
|-------|--------|
| head=[1,2,3,4,5], n=2 | [1,2,3,5] |
| head=[1], n=1 | [] |
| head=[1,2], n=1 | [1] |

---

## Approach - Two Pointers (Fast-Slow with Gap) - One Pass
list = 1->2->3->4->5   n=2
dummy->1->2->3->4->5
fast=slow=dummy
Move fast n(2) steps ahead:
fast = dummy->1->2 (at node 2)
Now move both until fast.next is null:
slow=dummy, fast=2 → slow=1, fast=3 → slow=2, fast=4 → slow=3, fast=5(fast.next=null, stop)
slow is at node 3, slow.next(4) should be removed
slow.next = slow.next.next → 3->5
Result: 1->2->3->5 ✓

- **Dummy node** use karo edge cases handle karne ke liye (jaise head hi remove karna ho)
- `fast` pointer ko pehle `n` steps aage badhao
- Fir dono (`fast`, `slow`) ko **saath** me move karo jab tak `fast->next` null na ho jaye
- Ab `slow` us node pe hoga jo **target node se pehle** hai
- `slow->next = slow->next->next` se target node skip kar do
- Ye **single pass** me hi solve ho jata hai

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* fast = &dummy;
        ListNode* slow = &dummy;

        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;

        return dummy.next;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)
