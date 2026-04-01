<div align="center">

# 1022. Sum of Root To Leaf Binary Numbers

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Trees-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-DFS_Recursion-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Binary tree diya hai jisme har node ki value `0` ya `1` hai.  
Root se leaf tak ka har path ek binary number represent karta hai.  
Saare leaf paths ke binary numbers ka **sum** return karo.

---

## Examples

| Input | Output | Explanation |
|-------|--------|-------------|
| `[1,0,1,0,1,0,1]` | `22` | 100+101+110+111 = 4+5+6+7 = 22 |
| `[0]` | `0` | Sirf ek node |

---

## Approach — DFS Recursion

```
Tree:
        1
       / \
      0   1
     / \ / \
    0  1 0  1

Root se leaf tak DFS karo, har step pe:
  cur = cur * 2 + node->val

Path 1→0→0: cur = 0→1→2→4   = 4  (100)
Path 1→0→1: cur = 0→1→2→5   = 5  (101)
Path 1→1→0: cur = 0→1→3→6   = 6  (110)
Path 1→1→1: cur = 0→1→3→7   = 7  (111)

Sum = 4+5+6+7 = 22 ✓
```

- `cur * 2` se left shift hota hai (binary mein ek bit aage badhta hai)
- `+ root->val` se current bit add hoti hai
- Leaf mile to `cur` return karo
- Left aur right dono subtrees ka sum return karo

---

## Complexity

| | |
|---|---|
| Time | O(n) |
| Space | O(h) |

> n = total nodes, h = height of tree

---

## Solution

```cpp
class Solution {
public:
    int solve(TreeNode* root, int cur) {
        if (root == NULL) return 0;

        cur = cur * 2 + root->val;

        if (root->left == NULL && root->right == NULL) return cur;

        return solve(root->left, cur) + solve(root->right, cur);
    }

    int sumRootToLeaf(TreeNode* root) {
        return solve(root, 0);
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/)