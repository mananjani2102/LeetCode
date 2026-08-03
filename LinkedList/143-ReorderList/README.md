<div align="center">

# 143. Reorder List

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-LinkedList-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Middle_Reverse_Merge-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given head of singly linked list L0→L1→...→Ln, reorder it to L0→Ln→L1→Ln-1→L2→... in-place, without changing node values.

---

## Examples

| Input | Output |
|-------|--------|
| [1,2,3,4] | [1,4,2,3] |
| [1,2,3,4,5] | [1,5,2,4,3] |

---

## Approach - Find Middle + Reverse Second Half + Merge Alternately

list = 1->2->3->4->5

Step 1 - Find middle (slow/fast pointers):
slow ends at 3 (middle)

Step 2 - Reverse second half (after middle):
Original: 4->5
Reversed: 5->4
firstHalf: 1->2->3 (slow.next set to null)

Step 3 - Merge alternately:
first=1, second=5
1->5, first=2, second=4
2->4, first=3, second=null(temp2)
3->4 (already linked from before)

Result: 1->5->2->4->3 ✓


- **Fast/slow pointer** se list ka middle dhundo
- Second half ko **reverse** karo
- Do halves ko **alternately merge** karo — pehle first half ka node, phir second half ka node, aage badhte raho
- Ye sab **in-place** hota hai, node values change nahi hote, sirf pointers rearrange hote hain

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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        while (head) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* secondHalf = reverseList(slow->next);
        slow->next = nullptr;

        ListNode* firstHalf = head;

        while (secondHalf) {
            ListNode* temp1 = firstHalf->next;
            ListNode* temp2 = secondHalf->next;

            firstHalf->next = secondHalf;
            secondHalf->next = temp1;

            firstHalf = temp1;
            secondHalf = temp2;
        }
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/reorder-list/)
