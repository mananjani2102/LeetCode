<div align="center">

# 24. Swap Nodes in Pairs

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-LinkedList-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Dummy_Node_Pointer_Swap-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given a linked list, swap every two adjacent nodes and return head. Must swap actual nodes (not just values).

---

## Examples

| Input | Output |
|-------|--------|
| [1,2,3,4] | [2,1,4,3] |
| [] | [] |
| [1] | [1] |
| [1,2,3] | [2,1,3] |

---

## Approach - Dummy Node + Pointer Manipulation

list = 1->2->3->4

dummy->1->2->3->4
prev=dummy

Iteration 1: first=1, second=2
first.next = second.next(3) → 1->3
second.next = first → 2->1
prev.next = second → dummy->2
Now: dummy->2->1->3->4
prev = first(1)

Iteration 2: first=3, second=4
first.next = second.next(null) → 3->null
second.next = first → 4->3
prev.next = second → 1->4
Now: dummy->2->1->4->3
prev = first(3)

Loop ends (prev.next.next is null)

Result: 2->1->4->3 ✓


- **Dummy node** use karo taaki head swap bhi easily handle ho sake
- `prev` pointer se pairs traverse karo — jab tak agle do nodes exist karte hain
- Har pair ke liye: `first` aur `second` node identify karo
- Pointers rearrange karo: `first->next = second->next`, `second->next = first`, `prev->next = second`
- `prev` ko `first` pe move karo (jo ab pair ka **doosra** node ban gaya hai) agle pair ke liye ready hone ke liye

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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;

        while (prev->next && prev->next->next) {
            ListNode* first = prev->next;
            ListNode* second = first->next;

            first->next = second->next;
            second->next = first;
            prev->next = second;

            prev = first;
        }

        return dummy.next;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/swap-nodes-in-pairs/)
