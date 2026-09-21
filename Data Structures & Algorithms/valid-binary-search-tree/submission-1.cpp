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
    bool dfsBST(TreeNode* root, int lo, int hi) {
        if (!root)
            return true;

        // not in the valid range
        if (root->val <= lo || root->val >= hi)
            return false;
        
        // doesn't 
        // if (root->left > root->val || root->right < root->val)
        //     return false;

        return dfsBST(root->left, lo, root->val) && dfsBST(root->right, root->val, hi);
    }

    bool isValidBST(TreeNode* root) {
        return dfsBST(root, INT_MIN, INT_MAX);
    }
};
