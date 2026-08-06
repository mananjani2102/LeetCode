<div align="center">

# 430. Flatten a Multilevel Doubly Linked List

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-LinkedList-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Iterative_DFS-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given a multilevel doubly linked list where nodes may have a child pointer to another doubly linked list, flatten it into a single-level doubly linked list. Child list nodes should appear right after curr and before curr.next.

---

## Examples

| Input | Output |
|-------|--------|
| [1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12] | [1,2,3,7,8,11,12,9,10,4,5,6] |
| [1,2,null,3] | [1,3,2] |
| [] | [] |

---

## Approach - Iterative DFS

1<->2 with 2.child=3

curr=1: no child, curr=curr.next=2
curr=2: has child(3)!
nextNode = curr.next = null (2 was last)
childHead = 3
curr.next = 3, 3.prev = curr(2), curr.child = null
childTail = 3 (no further next)
childTail.next = nextNode(null)
curr = curr.next = 3

curr=3: no child, curr=curr.next=null, loop ends

Result: 1 <-> 2 <-> 3 ✓


- Har node ko traverse karo, agar `curr->child` exists karta hai to:
  - `curr->next` (jo baad me aana chahiye) ko save karo
  - `curr->next` ko `child` list ke head se link karo
  - `child` list ke **end tak traverse** karo (`childTail` dhundo)
  - `childTail->next` ko saved `nextNode` se link karo
  - `curr->child` ko `null` set karo (requirement ke mutabik)
- Ye process **iteratively** chalta rehta hai jab tak poori list flatten na ho jaye

---

## Complexity

| | |
|---|---|
| Time | O(n) |
| Space | O(1) extra (iterative, no recursion stack) |

---

## Solution

```cpp
class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return head;

        Node* curr = head;

        while (curr) {
            if (curr->child) {
                Node* nextNode = curr->next;
                Node* childHead = curr->child;

                curr->next = childHead;
                childHead->prev = curr;
                curr->child = nullptr;

                Node* childTail = childHead;
                while (childTail->next) {
                    childTail = childTail->next;
                }

                childTail->next = nextNode;
                if (nextNode) {
                    nextNode->prev = childTail;
                }
            }
            curr = curr->next;
        }

        return head;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/)
