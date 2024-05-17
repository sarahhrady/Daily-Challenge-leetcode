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
    void bfs(TreeNode*& root, int target){
        if(root==nullptr)return;

        bfs(root->left, target);
        bfs(root->right, target);
        if(root->right==nullptr&&root->left==nullptr&&root->val==target)
        {
            root=nullptr;
            return;
        }

        return;
        
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        bfs(root,target);
        return root;
    }
};