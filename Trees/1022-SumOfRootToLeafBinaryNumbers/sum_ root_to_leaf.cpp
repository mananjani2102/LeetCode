// LeetCode 1022 - Sum of Root To Leaf Binary Numbers
// Approach: DFS Recursion
// Time: O(n) | Space: O(h)  [h = height of tree]

#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode()                                : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x)                           : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l),       right(r)       {}
};

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

TreeNode* buildTree(vector<int> vals) {
    if (vals.empty() || vals[0] == -1) return nullptr;
    TreeNode* root = new TreeNode(vals[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < vals.size()) {
        TreeNode* node = q.front(); q.pop();
        if (i < vals.size() && vals[i] != -1) {
            node->left = new TreeNode(vals[i]);
            q.push(node->left);
        }
        i++;
        if (i < vals.size() && vals[i] != -1) {
            node->right = new TreeNode(vals[i]);
            q.push(node->right);
        }
        i++;
    }
    return root;
}

int main() {
    Solution sol;

    TreeNode* r1 = buildTree({1,0,1,0,1,0,1});
    cout << sol.sumRootToLeaf(r1) << endl;  

    TreeNode* r2 = buildTree({0});
    cout << sol.sumRootToLeaf(r2) << endl; 

    return 0;
}