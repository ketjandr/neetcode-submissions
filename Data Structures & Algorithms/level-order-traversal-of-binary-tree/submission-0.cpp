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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root)
            return {};
        
        // queue for bfs
        queue<TreeNode*> q;
        q.push(root);
        int batchSize = 1;
        int level = 0;

        // vector to hold result
        vector<vector<int>> res(1);

        while (!q.empty()) {
            if (batchSize == 0) {
                batchSize = q.size();
                level++;
                res.push_back({});
            }
                

            TreeNode* curr = q.front();
            q.pop();
            

            if (curr->left) 
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
            
            res[level].push_back(curr->val);
            batchSize--;
        }

        return res;
    }
};
