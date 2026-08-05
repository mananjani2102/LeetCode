<div align="center">

# 160. Intersection of Two Linked Lists

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-LinkedList-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Two_Pointers_Switch-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given heads of two singly linked lists, return the node where they intersect, or null if no intersection. Follow up: O(m+n) time, O(1) space.

---

## Examples

| Input | Output |
|-------|--------|
| listA=[4,1,8,4,5], listB=[5,6,1,8,4,5], intersect at 8 | Node with value 8 |
| listA=[2,6,4], listB=[1,5], no intersection | null |

---

## Approach - Two Pointers (Switch Lists at End)

listA = 4->1->8->4->5 (length 5)
listB = 5->6->1->8->4->5 (length 6, shares tail 8->4->5 with A)

a starts at headA, b starts at headB

Traverse together. When a reaches end, switch to headB.
When b reaches end, switch to headA.

This equalizes the "extra" length difference between lists.
Eventually both pointers meet exactly at the intersection node (or both become null if no intersection).

a and b will have traveled: lenA + lenB - commonLen = lenB + lenA - commonLen (same total distance)
→ They meet at intersection point ✓


- Do pointers `a` aur `b` rakho, `headA` aur `headB` se start karo
- Jab koi pointer apni list ke end tak pahunch jaye (`null` ho jaye), use **doosri list ke head** pe switch kar do
- Is trick se dono pointers **exactly same total distance** travel karte hain (chahe lists ki length alag ho)
- Isliye wo ya to **intersection point** pe milte hain, ya dono `null` ho jate hain (agar intersection nahi hai)
- O(1) space me O(m+n) time me solve ho jata hai — follow-up requirement satisfy hoti hai

---

## Complexity

| | |
|---|---|
| Time | O(m + n) |
| Space | O(1) |

---

## Solution

```cpp
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;

        ListNode* a = headA;
        ListNode* b = headB;

        while (a != b) {
            a = a ? a->next : headB;
            b = b ? b->next : headA;
        }

        return a;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/intersection-of-two-linked-lists/)
