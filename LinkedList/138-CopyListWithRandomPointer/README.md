<div align="center">

# 138. Copy List with Random Pointer

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Linked_List-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-HashMap_Two_Pass-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given a linked list where each node has an extra `random` pointer (pointing to any node or null), return a deep copy of the list — new nodes only, same structure and random links.

---

## Examples

| Input | Output |
|-------|--------|
| [[7,null],[13,0],[11,4],[10,2],[1,0]] | [[7,null],[13,0],[11,4],[10,2],[1,0]] |
| [[1,1],[2,1]] | [[1,1],[2,1]] |
| [[3,null],[3,0],[3,null]] | [[3,null],[3,0],[3,null]] |

---

## Approach - HashMap Two Pass
head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Nodes: N0(7) N1(13) N2(11) N3(10) N4(1)
randoms: N1→N0, N2→N4, N3→N2, N4→N0

Pass 1 (create clones, no links yet):
mapping = { N0:7', N1:13', N2:11', N3:10', N4:1' }

Pass 2 (wire next + random using mapping):
N0': next=mapping[N1]=13', random=mapping[null]=null
N1': next=mapping[N2]=11', random=mapping[N0]=7'
N2': next=mapping[N3]=10', random=mapping[N4]=1'
N3': next=mapping[N4]=1',  random=mapping[N2]=11'
N4': next=mapping[null]=null, random=mapping[N0]=7'

return mapping[head] = 7'

Result: 7' → 13' → 11' → 10' → 1' ✓ (with same random pattern as original)


- Pehle pass me **har original node ke liye ek naya clone node banao** aur `unordered_map<Node*, Node*>` me old→new mapping store karo
- Doosre pass me har clone ka `next` aur `random` set karo — `mapping[curr->next]` aur `mapping[curr->random]` use karke, isse original ke pointers automatically naye nodes pe map ho jate hai
- Agar `curr->next` ya `curr->random` **null** hai, to `mapping[null]` bhi safely `null` hi return karta hai (map me na hone par default value insert hoti hai)
- Do passes zaroori hai kyunki **random pointer kisi bhi future node ko point kar sakta hai** — jab tak saare nodes clone na ho jaye, hum unka mapping nahi kar sakte

---

## Complexity

| | |
|---|---|
| Time | O(n) |
| Space | O(n) |

---

## Solution

```cpp
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;

        unordered_map<Node*, Node*> mapping;

        Node* curr = head;
        while (curr) {
            mapping[curr] = new Node(curr->val);
            curr = curr->next;
        }

        curr = head;
        while (curr) {
            mapping[curr]->next = mapping[curr->next];
            mapping[curr]->random = mapping[curr->random];
            curr = curr->next;
        }

        return mapping[head];
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/copy-list-with-random-pointer/)
