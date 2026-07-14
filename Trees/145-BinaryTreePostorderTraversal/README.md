<div align="center">

# 145. Binary Tree Postorder Traversal

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Trees-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Iterative_Two_Stack-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given root of binary tree, return postorder traversal (left, right, root) of node values. Follow up: solve iteratively.

---

## Examples

| Input | Output |
|-------|--------|
| [1,null,2,3] | [3,2,1] |
| [] | [] |
| [1] | [1] |

---

## Approach - Iterative Two Stack
tree:  1

2
/
3
st1=[1]
pop 1 → st2=[1], push left(none), push right(2) → st1=[2]
pop 2 → st2=[1,2], push left(3), push right(none) → st1=[3]
pop 3 → st2=[1,2,3], no children → st1=[]
st1 empty, reverse st2 order (pop from st2):
pop 3, pop 2, pop 1 → result=[3,2,1] ✓

- Postorder = **Left, Right, Root** — normally recursion se easy hai, lekin iteratively karne ke liye smart trick chahiye
- **Two stacks** use karo: `st1` root-right-left order me process karta hai (isse reverse postorder milta hai)
- `st1` se pop karke `st2` me push karo, aur children ko `st1` me push karo (pehle left, phir right — taaki right pehle pop ho)
- Jab `st1` empty ho jaye, `st2` ko pop karo — wahi correct postorder sequence dega

**Follow-up:** Iterative solution upar diya hai using two-stack method — bina recursion ke.

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) return result;

        stack<TreeNode*> st1;
        stack<TreeNode*> st2;

        st1.push(root);

        while (!st1.empty()) {
            TreeNode* node = st1.top();
            st1.pop();
            st2.push(node);

            if (node->left) st1.push(node->left);
            if (node->right) st1.push(node->right);
        }

        while (!st2.empty()) {
            result.push_back(st2.top()->val);
            st2.pop();
        }

        return result;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/binary-tree-postorder-traversal/)
