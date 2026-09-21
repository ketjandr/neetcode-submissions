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
    void goodNodesWorker(TreeNode* root, int maxSoFar, int& count) {
        if (!root)
            return;
        
        if (maxSoFar <= root->val) {
            count++;
            maxSoFar = root->val;
        }

        goodNodesWorker(root->left, maxSoFar, count);
        goodNodesWorker(root->right, maxSoFar, count);
    }

    int goodNodes(TreeNode* root) {
        int count = 0;
        goodNodesWorker(root, root->val, count);
        return count;
    }
};
