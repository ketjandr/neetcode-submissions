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
    TreeNode* construct(vector<int>& preorder, unordered_map<int, int>& inorderMap, int lo, int hi, int &preorderIdx) {
        if (lo > hi)
            return nullptr;
        
        int val = preorder[preorderIdx];
        int inorderIdx = inorderMap[val];

        preorderIdx++;

        return new TreeNode(val,
                        construct(preorder, inorderMap, lo, inorderIdx - 1, preorderIdx),
                        construct(preorder, inorderMap, inorderIdx + 1, hi, preorderIdx));

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // build hash table to store the inorder nodes
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); ++i) {
            inorderMap[inorder[i]] = i;
        }

        int preorderIdx = 0;
        return construct(preorder, inorderMap, 0, preorder.size() - 1, preorderIdx);
    }
};
