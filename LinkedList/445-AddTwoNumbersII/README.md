<div align="center">

# 445. Add Two Numbers II

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Linked_List-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Stack-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given two non-empty linked lists representing non-negative integers with most significant digit first, add the numbers and return the sum as a linked list (no leading zeros, except 0 itself).

---

## Examples

| Input | Output |
|-------|--------|
| l1=[7,2,4,3], l2=[5,6,4] | [7,8,0,7] |
| l1=[2,4,3], l2=[5,6,4] | [8,0,7] |
| l1=[0], l2=[0] | [0] |

---

## Approach - Stack
l1=[2,4,3], l2=[5,6,4]

push all l1 digits → s1(top→bottom): 3,4,2
push all l2 digits → s2(top→bottom): 4,6,5
carry=0, head=null

iter1: sum=0+3+4=7 → carry=0, digit=7 → node(7)->next=null → head=[7]
iter2: sum=0+4+6=10 → carry=1, digit=0 → node(0)->next=[7] → head=[0,7]
iter3: sum=1+2+5=8 → carry=0, digit=8 → node(8)->next=[0,7] → head=[8,0,7]
s1,s2 both empty, carry=0 → loop ends

Result = [8,0,7] ✓


- Reversing se bachne ke liye dono lists ke digits ko **do stacks** me push kar do — isse **least significant digit** har stack ke top pe aa jata hai, bina original list ko modify kiye
- Dono stacks jab tak empty na ho (ya carry bacha ho), pop karte hue **top digits ko add** karo, saath me pichla `carry` bhi jodo
- `sum % 10` current digit hai aur `sum / 10` naya `carry` — is digit ka naya node banao aur use **result list ke front me insert** karo (`node->next = head; head = node`) — isse result apne aap most-significant-first order me ban jata hai, bina kahi reverse kiye
- Loop tab tak chalta hai jab tak dono stacks empty na ho jaaye **aur** carry bhi 0 ho jaaye (last carry se ek extra digit ban sakta hai, jaise 999+1)
- Ye approach input lists ko bilkul reverse nahi karti — follow-up requirement satisfy hoti hai, sirf extra O(m+n) space (stacks) lagta hai

---

## Complexity

| | |
|---|---|
| Time | O(m+n) |
| Space | O(m+n) |

---

## Solution

```cpp
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;

        while (l1) { s1.push(l1->val); l1 = l1->next; }
        while (l2) { s2.push(l2->val); l2 = l2->next; }

        int carry = 0;
        ListNode* head = NULL;

        while (!s1.empty() || !s2.empty() || carry) {
            int sum = carry;
            if (!s1.empty()) { sum += s1.top(); s1.pop(); }
            if (!s2.empty()) { sum += s2.top(); s2.pop(); }

            carry = sum / 10;
            ListNode* node = new ListNode(sum % 10);
            node->next = head;
            head = node;
        }

        return head;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/add-two-numbers-ii/)
