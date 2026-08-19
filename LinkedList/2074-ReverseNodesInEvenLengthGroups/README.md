<div align="center">

# 2074. Reverse Nodes in Even Length Groups

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Linked_List-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-In_Place_Group_Reversal-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given head of a linked list, nodes are assigned to groups of length 1,2,3,4,... sequentially (last group may be shorter). Reverse the nodes only inside groups whose actual length is even, and return the modified list.

---

## Examples

| Input | Output |
|-------|--------|
| [5,2,6,3,9,1,7,3,8,4] | [5,6,2,3,9,1,4,8,3,7] |
| [1,1,0,6] | [1,0,1,6] |
| [1,1,0,6,5] | [1,0,1,5,6] |

---

## Approach - In Place Group Reversal
head = [5,2,6,3,9,1,7,3,8,4]
prevGroupEnd=5, groupNumber=1, curr=2

Group2 (groupLen=2): nodes = 2,6 → count=2 (even)
  nextGroupStart=3
  reverse 2..6 → 6→2→(links to 3)
  prevGroupEnd(5)->next=6, prevGroupEnd=2
  list so far: 5→6→2→3→9→1→7→3→8→4
  curr=3

Group3 (groupLen=3): nodes = 3,9,1 → count=3 (odd, only 3 nodes available and 3==groupLen)
  no reversal, prevGroupEnd=1(node)
  curr=7

Group4 (groupLen=4): nodes = 7,3,8,4 → count=4 (even, last group, exactly 4 left)
  nextGroupStart=null
  reverse 7,3,8,4 → 4→8→3→7→null
  prevGroupEnd(1)->next=4, prevGroupEnd=7
  curr=null → loop ends

Final: 5→6→2→3→9→1→4→8→3→7 ✓


- `groupNumber` ko 1 se start karke har naye group ke liye **1 se increment** karo (group lengths: 1,2,3,4,...) — pehla group (single node) kabhi reverse nahi hota isliye seedha `curr=head->next` se shuru karte hai
- Har group ke liye pehle **actual node count** nikalo — ye `groupLen` se kam bhi ho sakta hai agar list khatam ho rahi ho (last group), isliye `node->next` check karte hue traverse karo
- Agar `count` **even** hai to us group ko standard in-place linked list reversal se reverse karo — reversal ke baad `prevGroupEnd->next` ko naye group-head (jo pehle group ka last node tha) se jodo, aur `prevGroupEnd` ko group ka naya tail (jo pehle group ka first node tha) bana do
- Agar `count` **odd** hai to kuch reverse nahi hota, bas `prevGroupEnd` ko is group ke last node pe move kar do
- Poora kaam **existing nodes ke pointers hi rewire** karke hota hai, koi extra node ya array nahi banta — isliye **O(1) space**

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
    ListNode* reverseEvenGroups(ListNode* head) {
        ListNode* prevGroupEnd = head;
        int groupNumber = 1;
        ListNode* curr = head->next;

        while (curr) {
            groupNumber++;
            int groupLen = groupNumber;

            ListNode* node = curr;
            int count = 1;
            while (count < groupLen && node->next) {
                node = node->next;
                count++;
            }

            ListNode* nextGroupStart = node->next;

            if (count % 2 == 0) {
                ListNode* prev = nextGroupStart;
                ListNode* cur2 = curr;
                for (int i = 0; i < count; i++) {
                    ListNode* nxt = cur2->next;
                    cur2->next = prev;
                    prev = cur2;
                    cur2 = nxt;
                }
                prevGroupEnd->next = node;
                prevGroupEnd = curr;
            } else {
                prevGroupEnd = node;
            }

            curr = nextGroupStart;
        }

        return head;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/reverse-nodes-in-even-length-groups/)
