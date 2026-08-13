<div align="center">

# 1019. Next Greater Node In Linked List

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Stack-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Monotonic_Stack-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given head of linked list, for each node find the value of first next node with strictly larger value. Return array of these values (0 if none).

---

## Examples

| Input | Output |
|-------|--------|
| [2,1,5] | [5,5,0] |
| [2,7,4,3,5] | [7,0,5,5,0] |

---

## Approach - Monotonic Stack (Convert to Array First)

head = [2,7,4,3,5]

Convert to array: values=[2,7,4,3,5]

i=0(2): stack=[] → push 0 → stack=[0]
i=1(7): values[0]=2<7 → pop 0, result[0]=7
stack empty → push 1 → stack=[1]
i=2(4): values[1]=7>=4 → push 2 → stack=[1,2]
i=3(3): values[2]=4>=3 → push 3 → stack=[1,2,3]
i=4(5): values[3]=3<5 → pop 3, result[3]=5
values[2]=4<5 → pop 2, result[2]=5
values[1]=7>=5 → stop
push 4 → stack=[1,4]

Leftover in stack (indices 1,4) → result[1]=0, result[4]=0

Result: [7,0,5,5,0] ✓


- Pehle linked list ko **array** me convert karo taaki indices se easily access ho sake
- **Monotonic decreasing stack** maintain karo — stack me indices store karo
- Har naya element ke liye: jab tak stack ka top **current se chota** hai, unhe pop karo aur unka answer set karo (current value hi unka next greater hai)
- Current index push karo
- Jo indices stack me **bache reh jate hain** unka koi next greater nahi mila, unka answer default `0` rehta hai

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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> values;
        while (head) {
            values.push_back(head->val);
            head = head->next;
        }

        int n = values.size();
        vector<int> result(n, 0);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && values[st.top()] < values[i]) {
                result[st.top()] = values[i];
                st.pop();
            }
            st.push(i);
        }

        return result;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/next-greater-node-in-linked-list/)
