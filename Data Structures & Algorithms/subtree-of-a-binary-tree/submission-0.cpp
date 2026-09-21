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
    // check if trees root1 == root2
    bool isEqual(TreeNode* root1, TreeNode* root2) {
        // base cases
        if (!root1 && !root2)
            return true;
        
        if(!root1 || !root2)
            return false;
        
        if(root1->val != root2->val)
            return false;
        
        return isEqual(root1->left, root2->left) && isEqual(root1->right, root2->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // base cases
        if (!subRoot)
            return true;
        
        if(!root)
            return false;
        
        if(isEqual(root, subRoot))
            return true;
        
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
