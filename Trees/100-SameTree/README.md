<div align="center">

# 100. Same Tree

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Trees-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Recursive_DFS-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given roots of two binary trees p and q, check if they are structurally identical with same node values.

---

## Examples

| Input | Output |
|-------|--------|
| p=[1,2,3], q=[1,2,3] | true |
| p=[1,2], q=[1,null,2] | false |
| p=[1,2,1], q=[1,1,2] | false |

---

## Approach - Recursive DFS
p = [1,2,3]   q = [1,2,3]
isSameTree(1,1):
values match ✓
isSameTree(2,2): both leaf, match ✓
isSameTree(3,3): both leaf, match ✓
→ true

- Dono nodes `null` hain → `true` (both empty)
- Ek `null` hai dusra nahi → `false` (structure mismatch)
- Values match nahi karte → `false`
- Warna left aur right subtrees ko **recursively** check karo

---

## Complexity

| | |
|---|---|
| Time | O(n) where n = total nodes |
| Space | O(h) where h = tree height (recursion stack) |

---

## Solution

```cpp
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        if (p->val != q->val) return false;

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/same-tree/)
