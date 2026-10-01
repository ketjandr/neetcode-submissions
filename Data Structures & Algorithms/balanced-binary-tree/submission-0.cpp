/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isBalancedDfs(TreeNode* root, int& height) {
        if (!root) {
            height = 0;
            return true;
        }

        int height1 = -1;
        int height2 = -1;

        if (!isBalancedDfs(root->left, height1) || !isBalancedDfs(root->right, height2))
            return false;

        if (abs(height1 - height2) > 1)
            return false;
        
        height = max(height1, height2) + 1;
        return true;
    }

    bool isBalanced(TreeNode* root) {
        int height = -1;
        return isBalancedDfs(root, height);
    }
};
