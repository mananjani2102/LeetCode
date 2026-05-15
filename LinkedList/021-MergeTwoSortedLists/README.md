<div align="center">

# 21. Merge Two Sorted Lists

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-LinkedList-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Dummy_Node-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given heads of two **sorted linked lists**, merge them into one sorted list by splicing existing nodes together.

---

## Examples

| Input | Output |
|-------|--------|
| list1=[1,2,4], list2=[1,3,4] | [1,1,2,3,4,4] |
| list1=[], list2=[] | [] |
| list1=[], list2=[0] | [0] |

---

## Approach — Dummy Node + Two Pointers
list1 = 1 → 2 → 4

list2 = 1 → 3 → 4
dummy → tail
Compare 1,1 → list1<=list2 → tail.next=list1(1), list1=2

Compare 2,1 → list2<list1 → tail.next=list2(1), list2=3

Compare 2,3 → list1<list2 → tail.next=list1(2), list1=4

Compare 4,3 → list2<list1 → tail.next=list2(3), list2=4

Compare 4,4 → list1<=list2 → tail.next=list1(4), list1=null

list1 empty → tail.next=list2(4)
Result: 1→1→2→3→4→4 ✓

- `dummy` node se start karo, `tail` pointer rakho
- Dono lists compare karo, **chota wala** node tail ke `next` me lagao
- List khatam hone tak loop chalao
- Bachi hui list ko seedha attach kar do

---

## Complexity

| | |
|---|---|
| Time | O(n + m) |
| Space | O(1) |

---

## Solution

```cpp
// LeetCode 21 - Merge Two Sorted Lists
// Approach: Dummy Node + Two Pointers
// Time: O(n+m) | Space: O(1)

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (list1 && list2) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        if (list1) tail->next = list1;
        else tail->next = list2;

        return dummy.next;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/merge-two-sorted-lists/)
