<div align="center">

# 141. Linked List Cycle

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-LinkedList-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Floyd_Cycle_Detection-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given head of linked list, determine if it has a cycle. Solve using O(1) memory.

---

## Examples

| Input | Output |
|-------|--------|
| [3,2,0,-4], pos=1 | true |
| [1,2], pos=0 | true |
| [1], pos=-1 | false |

---

## Approach - Floyd's Cycle Detection (Fast-Slow Pointer)

list with cycle: 3->2->0->-4->(back to 2)

slow=3, fast=3

Step1: slow=2, fast=0
Step2: slow=0, fast=2 (fast wrapped via cycle)
Step3: slow=-4, fast=-4

slow==fast → cycle detected! → true ✓


- **Floyd's Tortoise and Hare** algorithm — do pointers, ek **slow** (1 step) aur ek **fast** (2 steps)
- Agar list me cycle hai, fast pointer eventually slow ko **catch** kar lega (kyunki cycle ke andar wo baar baar loop karega)
- Agar `slow == fast` kabhi ho jaye to cycle hai
- Agar `fast` (ya `fast->next`) `null` ho jaye to list khatam ho gayi bina milen — **no cycle**
- Ye **O(1) space** me solve hota hai (koi extra HashSet nahi chahiye)

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
    bool hasCycle(ListNode *head) {

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != NULL && fast->next != NULL) {

            slow = slow->next;          
            fast = fast->next->next;    

            if (slow == fast) {
                return true;             
            }
        }

        return false;                    
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/linked-list-cycle/)
