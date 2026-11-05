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
        
        vector<vector<int>> res;

        queue<TreeNode*> q;
        q.push(root);
        int currItems = 0;
        int currLevel = -1;

        // bfs
        while (!q.empty()) {
            TreeNode *currNode = q.front();
            q.pop();
            
            // new level
            if (currItems == 0) {
                currLevel++;
                currItems = q.size();
                res.push_back({currNode->val});
            } else { // same level
                currItems--;
                res[currLevel].push_back(currNode->val);
            }

            if (currNode->left)
                q.push(currNode->left);

            if (currNode->right)
                q.push(currNode->right);
        }

        return res;
    }
};
