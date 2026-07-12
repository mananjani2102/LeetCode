<div align="center">

# 501. Find Mode in Binary Search Tree

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topic-Trees-blue?style=for-the-badge)
![Approach](https://img.shields.io/badge/Approach-Inorder_Traversal-purple?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus)

</div>

---

## Problem

Given root of a BST with duplicates, return all mode(s) - the most frequently occurring value(s). Follow up: solve without extra space (excluding recursion stack).

---

## Examples

| Input | Output |
|-------|--------|
| [1,null,2,2] | [2] |
| [0] | [0] |

---

## Approach - Inorder Traversal (O(1) space)
BST: 1

2
/
2
Inorder traversal visits: 1, 2, 2 (sorted order due to BST property)
curr=1: currVal=1, currCount=1 → maxCount=1, modes=[1]
curr=2: currVal=2, currCount=1 → currCount==maxCount → modes=[1,2]
curr=2: same as prev → currCount=2 → currCount>maxCount → maxCount=2, modes=[2]
Final modes = [2] ✓

- BST ka **inorder traversal** hamesha **sorted order** deta hai
- Isliye same value ke saare occurrences **consecutive** aate hain — extra HashMap ki zaroorat nahi
- Traversal karte waqt current value ka count track karo
- Agar naya max count mile to modes list reset karo, agar equal ho to add karo

---

## Complexity

| | |
|---|---|
| Time | O(n) |
| Space | O(h) recursion stack (not counted per problem constraints) |

---

## Solution

```cpp
class Solution {
public:
    int currVal;
    int currCount = 0;
    int maxCount = 0;
    vector<int> modes;

    void inorder(TreeNode* node) {
        if (!node) return;

        inorder(node->left);

        if (currCount > 0 && node->val == currVal) {
            currCount++;
        } else {
            currVal = node->val;
            currCount = 1;
        }

        if (currCount > maxCount) {
            maxCount = currCount;
            modes.clear();
            modes.push_back(currVal);
        } else if (currCount == maxCount) {
            modes.push_back(currVal);
        }

        inorder(node->right);
    }

    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return modes;
    }
};
```

---

## Link

[LeetCode Problem](https://leetcode.com/problems/find-mode-in-binary-search-tree/)
