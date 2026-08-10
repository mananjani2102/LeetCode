<div align="center">

# 61. Rotate List

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-LinkedList-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Circular_List-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given head of linked list, rotate the list to the right by k places.

---

## Examples

| Input | Output |
|-------|--------|
| head=[1,2,3,4,5], k=2 | [4,5,1,2,3] |
| head=[0,1,2], k=4 | [2,0,1] |

---

## Approach - Make Circular + Find New Break Point

list = 1->2->3->4->5 k=2
length=5

k = 2%5 = 2 (no reduction needed here)

Make circular: tail(5).next = head(1) → 1->2->3->4->5->1(loop)

stepsToNewTail = 5-2 = 3
newTail: start at head(1), move 2 more steps → newTail=3

newHead = newTail.next = 4
newTail.next = null (break the circle)

Result: 4->5->1->2->3 ✓


- Pehle list ki **length** nikalo, `tail` bhi identify kar lo
- `k = k % length` se **unnecessary full rotations** avoid karo (agar `k > length`)
- List ko **circular** bana do (`tail->next = head`)
- Naya break point dhundo: `stepsToNewTail = length - k` steps se `newTail` tak pahuncho
- `newTail->next` hi naya head hai, use save karke `newTail->next = nullptr` se circle todo

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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        int length = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            length++;
        }

        k = k % length;
        if (k == 0) return head;

        tail->next = head;

        int stepsToNewTail = length - k;
        ListNode* newTail = head;
        for (int i = 1; i < stepsToNewTail; i++) {
            newTail = newTail->next;
        }

        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/rotate-list/)
