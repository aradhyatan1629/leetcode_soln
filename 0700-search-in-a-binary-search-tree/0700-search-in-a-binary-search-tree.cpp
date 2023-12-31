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
    TreeNode *dfs(TreeNode *root,int val)
    {
        if(root==NULL)
            return NULL;
        if(root->val == val)
            return root;
        TreeNode *left = dfs(root->left,val);
        if(left)return left;
        TreeNode *right = dfs(root->right,val);
        if(right)return right;
        return NULL;
    }
    
    TreeNode* searchBST(TreeNode* root, int val) {
        return dfs(root,val);
    }
};