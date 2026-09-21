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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return nullptr;

        // find the first node where the paths diverge
        if (root->val <= p->val && root->val >= q->val ||
            root->val >= p->val && root->val <= q->val)
            return root;
        
        if (p->val < root->val)
            return lowestCommonAncestor(root->left, p, q);
        
        return lowestCommonAncestor(root->right, p, q);
    }
};
