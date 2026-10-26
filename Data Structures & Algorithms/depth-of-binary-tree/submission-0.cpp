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
    int dfsDepth(TreeNode* root, int heightSoFar) {
        if (!root)
            return heightSoFar;
        
        return 1 + max(dfsDepth(root->left, heightSoFar), dfsDepth(root->right, heightSoFar));
    }

    int maxDepth(TreeNode* root) {
        return dfsDepth(root, 0);
    }
};
