<div align="center">

# 002. Add Two Numbers

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Linked_List-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Iterative_Carry-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Do linked lists mein numbers **reverse order** mein store hain.  
Unhe add karo aur result bhi ek linked list ke form mein return karo.

---

## Examples

| l1 | l2 | Output | Explanation |
|----|----|--------|-------------|
| [2,4,3] | [5,6,4] | [7,0,8] | 342 + 465 = 807 |
| [0] | [0] | [0] | 0 + 0 = 0 |
| [9,9,9,9,9,9,9] | [9,9,9,9] | [8,9,9,9,0,0,0,1] | 9999999 + 9999 = 10009998 |

---

## Approach — Iterative with Carry

```
l1 = [2 → 4 → 3]
l2 = [5 → 6 → 4]

Step 1: 2 + 5 + carry(0) = 7  → node(7), carry = 0
Step 2: 4 + 6 + carry(0) = 10 → node(0), carry = 1
Step 3: 3 + 4 + carry(1) = 8  → node(8), carry = 0

Result: [7 → 0 → 8] ✓
```

- **Dummy node** se result list build karte hain
- Har step pe `sum = l1->val + l2->val + carry`
- `sum % 10` → naya node, `sum / 10` → agla carry
- Agar ek list khatam ho jaye, dusri continue hoti hai
- Loop tab bhi chalta hai jab sirf `carry` bacha ho (e.g. `9+9=18`)

---

## Complexity

| | |
|---|---|
| Time | O(max(m, n)) |
| Space | O(max(m, n)) |

> m = length of l1, n = length of l2

---

## Solution

```cpp
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* temp  = dummy;
        int carry = 0;

        while (l1 || l2 || carry) {
            int sum = carry;

            if (l1) { sum += l1->val; l1 = l1->next; }
            if (l2) { sum += l2->val; l2 = l2->next; }

            temp->next = new ListNode(sum % 10);
            carry      = sum / 10;
            temp       = temp->next;
        }

        return dummy->next;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/add-two-numbers/)