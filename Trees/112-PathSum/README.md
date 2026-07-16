<div align="center">

# 112. Path Sum

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Trees-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Recursive_DFS-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given root of binary tree and targetSum, return true if there exists a root-to-leaf path whose values sum to targetSum.

---

## Examples

| Input | Output |
|-------|--------|
| root=[5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum=22 | true |
| root=[1,2,3], targetSum=5 | false |
| root=[], targetSum=0 | false |

---

## Approach - Recursive DFS
root = [1,2,3]   targetSum = 5
hasPathSum(1, 5):
not leaf → remaining = 5-1 = 4
hasPathSum(2, 4): leaf → 2==4? No
hasPathSum(3, 4): leaf → 3==4? No
→ false

- `root` null hai → `false` (koi path nahi)
- **Leaf node** (no children) → check karo `root->val == targetSum`
- Warna `remaining = targetSum - root->val` nikal kar left aur right dono me **recursively** check karo
- Ek bhi taraf `true` mile to overall `true`

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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;

        if (!root->left && !root->right) {
            return root->val == targetSum;
        }

        int remaining = targetSum - root->val;

        return hasPathSum(root->left, remaining) || hasPathSum(root->right, remaining);
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/path-sum/)
