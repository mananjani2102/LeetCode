// LeetCode 112 - Path Sum
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;

        if (!root->left && !root->right) {
            return root->val == targetSum;
        }

        int remaining = targetSum - root->val;

        return hasPathSum(root->left, remaining) || hasPathSum(root->right, remaining);
    }
};

int main() {
    Solution sol;

    // Test 1: root=[5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum=22 → true
    TreeNode* leaf7 = new TreeNode(7);
    TreeNode* leaf2 = new TreeNode(2);
    TreeNode* node11 = new TreeNode(11, leaf7, leaf2);
    TreeNode* node4L = new TreeNode(4, node11, nullptr);
    TreeNode* leaf13 = new TreeNode(13);
    TreeNode* leaf1 = new TreeNode(1);
    TreeNode* node4R = new TreeNode(4, leaf13, leaf1);
    TreeNode* root1 = new TreeNode(5, node4L, node4R);
    cout << sol.hasPathSum(root1, 22) << endl; // 1 (true)

    // Test 2: root=[1,2,3], targetSum=5 → false
    TreeNode* root2 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    cout << sol.hasPathSum(root2, 5) << endl; // 0 (false)

    // Test 3: root=[], targetSum=0 → false
    TreeNode* root3 = nullptr;
    cout << sol.hasPathSum(root3, 0) << endl; // 0 (false)

    return 0;
}
