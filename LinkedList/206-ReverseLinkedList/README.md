<div align="center">

# 206. Reverse Linked List

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-LinkedList-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Iterative_Three_Pointers-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given head of a singly linked list, reverse the list and return the reversed head.

---

## Examples

| Input | Output |
|-------|--------|
| [1,2,3,4,5] | [5,4,3,2,1] |
| [1,2] | [2,1] |
| [] | [] |

---

## Approach - Iterative Three Pointers
list = 1 -> 2 -> 3 -> null
prev=null, curr=1
next=2, curr.next=prev(null) → 1->null
prev=1, curr=2
prev=1, curr=2
next=3, curr.next=prev(1) → 2->1->null
prev=2, curr=3
prev=2, curr=3
next=null, curr.next=prev(2) → 3->2->1->null
prev=3, curr=null
Loop ends, return prev(3)
Result: 3 -> 2 -> 1 ✓

- Teen pointers rakho: `prev`, `curr`, `next`
- Har node ke liye: `next` save karo, `curr->next` ko `prev` pe point karo (link reverse)
- `prev` aur `curr` dono ko aage badhao
- Loop khatam hone pe `prev` hi naya head hai

**Follow-up:** Recursive approach bhi possible hai — base case `head==null` return karta hai, fir `reverseList(head->next)` call karke links ko wapas reverse karte hain recursion unwind hote waqt.

---

## Complexity

| | |
|---|---|
| Time | O(n) |
| Space | O(1) iterative, O(n) recursive (call stack) |

---

## Solution

```cpp
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/reverse-linked-list/)
