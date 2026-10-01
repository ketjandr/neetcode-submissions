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
    void dfsRightSideTree(TreeNode* root, int level, int &currLevel, vector<int> &res) {
        if (!root)
            return;
        
        // we explored a new level
        if (level > currLevel) {
            res.push_back(root->val);
            currLevel++;
        }

        dfsRightSideTree(root->right, level + 1, currLevel, res);
        dfsRightSideTree(root->left, level + 1, currLevel, res);
    }

    vector<int> rightSideView(TreeNode* root) {
        // explore in a reverse-preorder traversal
        vector<int> res;
        int currLevel = -1;
        dfsRightSideTree(root, 0, currLevel, res);

        return res;
    }
};
