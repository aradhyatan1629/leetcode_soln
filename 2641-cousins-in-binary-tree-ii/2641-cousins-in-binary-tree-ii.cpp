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
    
    void dfs(TreeNode *root,unordered_map<int,int> &m,int level)
    {
        if(root==NULL)
            return;
        
        m[level]+=root->val;
        dfs(root->left,m,level+1);
        dfs(root->right,m,level+1);
    }
    
    void solve(TreeNode *root,unordered_map<int,int> &m,int level)
    {
        if(root==NULL)
            return;
        int s = 0;
        if(root->left) s += root->left->val;
        if(root->right) s += root->right->val;
        
        if(root->left) root->left->val = m[level+1] - s;
        if(root->right) root->right->val = m[level+1] - s;
        solve(root->left,m,level+1);
        solve(root->right,m,level+1);
    }
    
    
    TreeNode* replaceValueInTree(TreeNode* root) {
        unordered_map<int,int> m; //level,sum        
        dfs(root,m,0);
        solve(root,m,0);
        
        root->val = 0;
        return root;
    }
};