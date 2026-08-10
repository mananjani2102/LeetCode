<div align="center">

# 1290. Convert Binary Number in a Linked List to Integer

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-LinkedList-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Bit_Shifting-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given head of a linked list where each node value is 0 or 1 (binary representation, MSB at head), return the decimal value.

---

## Examples

| Input | Output |
|-------|--------|
| [1,0,1] | 5 |
| [0] | 0 |

---

## Approach - Bit Shifting While Traversing

list = 1->0->1

result=0
node=1: result = (0<<1)|1 = 1
node=0: result = (1<<1)|0 = 2
node=1: result = (2<<1)|1 = 5

Answer = 5 ✓ (binary 101 = decimal 5)


- Har node visit karte waqt, `result` ko **left shift** karo (`result << 1`, jo `result * 2` ke barabar hai) aur current bit ko **OR** karke add karo
- Ye bilkul aisa hai jaise manually binary ko decimal me convert karte hain — har naya digit purane result ko double karke naya bit add karta hai
- Single pass me poora number decode ho jata hai

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
    int getDecimalValue(ListNode* head) {
        int result = 0;

        while (head) {
            result = (result << 1) | head->val;
            head = head->next;
        }

        return result;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/)
