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
    bool bfs (TreeNode* root)
    {
        if(root->left==nullptr&&root->right==nullptr)
        {
            return root->val;
        }

        bool left = bfs(root->left);
        bool right = bfs(root->right);
        bool parent;
        if(root->val==2)
        {
            parent = left | right;
        } else{
            parent = left & right;
        }
        return parent;
    }
    bool evaluateTree(TreeNode* root) {
        return bfs(root);
    }
};