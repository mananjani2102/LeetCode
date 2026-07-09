<div align="center">

# 83. Remove Duplicates from Sorted List

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-LinkedList-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Single_Pass_Pointer-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given head of a sorted linked list, delete all duplicates so each element appears only once. Return the sorted list.

---

## Examples

| Input | Output |
|-------|--------|
| [1,1,2] | [1,2] |
| [1,1,2,3,3] | [1,2,3] |

---

## Approach - Single Pass Pointer
list = 1 -> 1 -> 2 -> 3 -> 3
curr=1: curr.val==curr.next.val(1==1) → skip next → 1->2->3->3
curr=1: curr.val==curr.next.val(1==2)? No → curr=curr.next(2)
curr=2: curr.val==curr.next.val(2==3)? No → curr=curr.next(3)
curr=3: curr.val==curr.next.val(3==3) → skip next → 1->2->3
Result: 1 -> 2 -> 3 ✓

- `curr` pointer se list traverse karo
- Agar `curr->val == curr->next->val` (duplicate hai) to `curr->next` ko skip kar do
- Warna `curr` ko aage badhao
- Sorted list hai isliye duplicates hamesha **adjacent** honge

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;

        while (curr && curr->next) {
            if (curr->val == curr->next->val) {
                curr->next = curr->next->next;
            } else {
                curr = curr->next;
            }
        }

        return head;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/remove-duplicates-from-sorted-list/)
