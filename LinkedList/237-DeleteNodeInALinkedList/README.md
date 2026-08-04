<div align="center">

# 237. Delete Node in a Linked List

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-LinkedList-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Copy_Value_Skip_Next-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given a node (not the last) in a singly linked list without access to head, delete that node in-place.

---

## Examples

| Input | Output |
|-------|--------|
| head=[4,5,1,9], node=5 | [4,1,9] |
| head=[4,5,1,9], node=1 | [4,5,9] |

---

## Approach - Copy Value, Skip Next Node

list = 4->5->1->9 node = "5" (second node)

Since we can't access head, we can't do normal deletion.
Trick: copy next node's value into current node, then skip next node.

node.val = node.next.val (5 becomes 1)
node.next = node.next.next (skip the "1" node, point to "9")

List becomes: 4->1->9 ✓ (effectively deleted "5")


- Kyunki hume `head` tak access nahi hai, hum normal "previous pointer se next skip karo" wala approach use nahi kar sakte
- Trick: **next node ki value** ko current node me **copy** kar do
- Fir current node ka `next` pointer next-next node pe point kar do (yani next node ko **skip** kar do)
- Effectively current node ab **agle node jaisa** ban jata hai, aur asli next node linked list se **remove** ho jata hai
- Ye O(1) time me solve ho jata hai, bina head access ke

---

## Complexity

| | |
|---|---|
| Time | O(1) |
| Space | O(1) |

---

## Solution

```cpp
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/delete-node-in-a-linked-list/)
