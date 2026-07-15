// LeetCode 100 - Same Tree
// Approach: Recursive DFS
// Time: O(n) | Space: O(h) where h = tree height

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        if (p->val != q->val) return false;

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main() {
    Solution sol;

    // Test 1: p=[1,2,3], q=[1,2,3] → true
    TreeNode* p1 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    TreeNode* q1 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    cout << sol.isSameTree(p1, q1) << endl; // 1 (true)

    // Test 2: p=[1,2], q=[1,null,2] → false
    TreeNode* p2 = new TreeNode(1, new TreeNode(2), nullptr);
    TreeNode* q2 = new TreeNode(1, nullptr, new TreeNode(2));
    cout << sol.isSameTree(p2, q2) << endl; // 0 (false)

    // Test 3: p=[1,2,1], q=[1,1,2] → false
    TreeNode* p3 = new TreeNode(1, new TreeNode(2), new TreeNode(1));
    TreeNode* q3 = new TreeNode(1, new TreeNode(1), new TreeNode(2));
    cout << sol.isSameTree(p3, q3) << endl; // 0 (false)

    return 0;
}
