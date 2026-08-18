<div align="center">

# 328. Odd Even Linked List

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Linked_List-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Two_Pointers-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given head of a singly linked list, group all odd-indexed nodes together followed by even-indexed nodes (relative order preserved within each group). Solve in O(1) extra space and O(n) time.

---

## Examples

| Input | Output |
|-------|--------|
| [1,2,3,4,5] | [1,3,5,2,4] |
| [2,1,3,5,6,4,7] | [2,3,6,7,1,5,4] |

---

## Approach - Two Pointers
head = [2,1,3,5,6,4,7]
odd=2, even=1, evenHead=1

iter1: odd.next=even.next(3) → odd=3; even.next=odd.next(5) → even=5
odd chain so far: 2→3 | even chain so far: 1→5

iter2: odd.next=even.next(6) → odd=6; even.next=odd.next(4) → even=4
odd chain: 2→3→6 | even chain: 1→5→4

iter3: odd.next=even.next(7) → odd=7; even.next=odd.next(null) → even=null
odd chain: 2→3→6→7 | even chain: 1→5→4→null
loop ends (even == null)

odd.next = evenHead(1) → final: 2→3→6→7→1→5→4

Answer = [2,3,6,7,1,5,4] ✓


- List ko traverse karte hue hi **do virtual sublists** bana lo — odd-indexed nodes ki chain aur even-indexed nodes ki chain
- `odd` aur `even` pointers rakho, aur `evenHead` me even chain ka starting node save karlo taaki baad me odd chain ke last node se jod sako
- Har step me `odd->next` ko agle odd node (`even->next`) pe point karo, aur `even->next` ko agle even node (`odd->next`) pe point karo — isse dono chains apne-apne alternate nodes ko pakadti jaati hai
- Jab `even` ya `even->next` null ho jaye, loop ruk jata hai — end me odd chain ke last node ka `next`, `evenHead` se jod do, poori list ek hi pass me ban jaati hai, bina koi naya node banaye (**O(1) space**)

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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;

        while (even && even->next) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }

        odd->next = evenHead;
        return head;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/odd-even-linked-list/)
