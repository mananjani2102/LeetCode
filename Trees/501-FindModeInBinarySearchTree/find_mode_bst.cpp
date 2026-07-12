// LeetCode 501 - Find Mode in Binary Search Tree
// Approach: Inorder Traversal (O(1) space, no extra map)
// Time: O(n) | Space: O(h) recursion stack (not counted per constraints)

#include <iostream>
#include <vector>
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

int main() {
    Solution sol;

    // Test 1: root=[1,null,2,2] → [2]
    TreeNode* root1 = new TreeNode(1, nullptr, new TreeNode(2, new TreeNode(2), nullptr));
    vector<int> r1 = sol.findMode(root1);
    for (int x : r1) cout << x << " ";
    cout << endl; // 2

    // Test 2: root=[0] → [0]
    Solution sol2;
    TreeNode* root2 = new TreeNode(0);
    vector<int> r2 = sol2.findMode(root2);
    for (int x : r2) cout << x << " ";
    cout << endl; // 0

    return 0;
}
