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
    int moves=0;
    int bfs(TreeNode* root)
    {
        if(root==nullptr)return 0;
        int l = bfs(root->left);
        int r = bfs(root->right);
        moves+=abs(l)+abs(r);
        return (root->val-1) + l + r;
    }
    int distributeCoins(TreeNode* root) {
        bfs(root);
        return moves;
    }
};