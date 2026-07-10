<div align="center">

# 234. Palindrome Linked List

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-LinkedList-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Fast_Slow_Pointer_Reverse-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given head of a singly linked list, return true if it is a palindrome. Follow up: solve in O(n) time and O(1) space.

---

## Examples

| Input | Output |
|-------|--------|
| [1,2,2,1] | true |
| [1,2] | false |

---

## Approach - Find Middle + Reverse Second Half + Compare
list = 1 -> 2 -> 2 -> 1
Step 1 - Fast/slow se middle dhundo:
slow reaches at second "2" (index 2)
Step 2 - Second half reverse karo:
1 -> 2 becomes 2 -> 1... reversed second half = 1 -> 2
Step 3 - Compare firstHalf aur reversed secondHalf:
1==1, 2==2 → match! → true ✓

- **Fast/slow pointer** se list ka middle dhundo (O(1) space)
- Second half ko **reverse** karo
- First half aur reversed second half ko **compare** karo character by character
- Sab match ho to palindrome hai

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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        while (head) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* secondHalf = reverseList(slow);
        ListNode* firstHalf = head;

        while (secondHalf) {
            if (firstHalf->val != secondHalf->val) return false;
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        return true;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/palindrome-linked-list/)
