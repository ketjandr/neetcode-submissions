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
    // returns the tree's height
    int dfsDiameter(TreeNode* root, int &diameter) {
        if (!root)
            return 0;

        int heightLeft = dfsDiameter(root->left, diameter);
        int heightRight = dfsDiameter(root->right, diameter);

        diameter = max(diameter, heightLeft + heightRight);
        return 1 + max(heightLeft, heightRight);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        dfsDiameter(root, diameter);
        return diameter;
    }
};
