<div align="center">

# 92. Reverse Linked List II

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-LinkedList-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-One_Pass_Dummy_Node-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given head of linked list and integers left, right, reverse the nodes from position left to right (1-indexed) and return the list.

---

## Examples

| Input | Output |
|-------|--------|
| head=[1,2,3,4,5], left=2, right=4 | [1,4,3,2,5] |
| head=[5], left=1, right=1 | [5] |

---

## Approach - One Pass with Dummy Node

list = 1->2->3->4->5 left=2, right=4

dummy->1->2->3->4->5
prev at position left-1=1 → prev points to node "1"
curr = prev.next = node "2"

Iteration 1 (right-left=2 times):
next = curr.next = 3
curr.next = next.next = 4
next.next = prev.next = 2
prev.next = next = 3
→ dummy->1->3->2->4->5

Iteration 2:
next = curr.next = 4
curr.next = next.next = 5
next.next = prev.next = 3
prev.next = next = 4
→ dummy->1->4->3->2->5

Result: 1->4->3->2->5 ✓


- **Dummy node** use karo, `prev` ko `left-1` position tak move karo (node jo reversal se pehle hai)
- `curr` ko `prev->next` set karo (reversal ka starting point, jo hamesha sabse pichhe rahega)
- **Head insertion technique**: har iteration me `curr` ke agle node ko nikal kar `prev->next` ke turant baad insert karo — ye effectively reversal karta hai
- `(right - left)` baar ye operation repeat karo
- Ye **single pass** me hi solve ho jata hai — follow-up requirement satisfy hoti hai

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;

        for (int i = 0; i < left - 1; i++) {
            prev = prev->next;
        }

        ListNode* curr = prev->next;

        for (int i = 0; i < right - left; i++) {
            ListNode* next = curr->next;
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
        }

        return dummy.next;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/reverse-linked-list-ii/)
