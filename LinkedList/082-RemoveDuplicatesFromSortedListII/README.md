<div align="center">

# 82. Remove Duplicates from Sorted List II

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-LinkedList-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Dummy_Node_Skip_All-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given head of sorted linked list, delete ALL nodes that have duplicates, leaving only distinct numbers. Return sorted list.

---

## Examples

| Input | Output |
|-------|--------|
| [1,2,3,3,4,4,5] | [1,2,5] |
| [1,1,1,2,3] | [2,3] |

---

## Approach - Dummy Node Skip All

list = 1->2->3->3->4->4->5

dummy->1->2->3->3->4->4->5
prev=dummy, curr=1

curr=1: curr.next(2).val != 1 → prev=1, curr=2
curr=2: curr.next(3).val != 2 → prev=2, curr=3
curr=3: curr.next(3).val == 3! duplicate found
dupVal=3, skip all 3's → curr moves to 4
prev.next = curr(4) → 2->4 (skipped both 3's)

curr=4: curr.next(4).val == 4! duplicate found
dupVal=4, skip all 4's → curr moves to 5
prev.next = curr(5) → 2->5

curr=5: curr.next=null → prev=5, curr=null

Result: 1->2->5 ✓


- **Dummy node** use karo taaki head bhi duplicate ho sake to handle ho jaye
- `prev` aur `curr` pointers rakho
- Agar `curr->val == curr->next->val` (duplicate group start hua), to **sabhi** us value ke nodes skip karo (ek loop se)
- Fir `prev->next` ko seedha duplicate group ke **baad wale node** se link karo
- Agar duplicate nahi mila, `prev` aur `curr` dono ko normally aage badhao

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
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;
        ListNode* curr = head;

        while (curr) {
            if (curr->next && curr->val == curr->next->val) {
                int dupVal = curr->val;
                while (curr && curr->val == dupVal) {
                    curr = curr->next;
                }
                prev->next = curr;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }

        return dummy.next;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/)
