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
    
    TreeNode *solve(TreeNode *root,unordered_map<int,int> &m,vector<TreeNode*> &ans)
    {
        if(root == NULL)
            return NULL;
        
        root->left = solve(root->left,m,ans);
        root->right = solve(root->right,m,ans);
        if(m[root->val] == 1)
        {
            if(root->left)
                ans.push_back(root->left);
            if(root->right)
                ans.push_back(root->right);
            return NULL;
        }
        return root;
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if(root==NULL)
            return {};
        unordered_map<int,int> m;
        for(int i=0;i<to_delete.size();i++)
            m[to_delete[i]]=1;
        
        vector<TreeNode*> ans;
        solve(root,m,ans);
        if(m[root->val] != 1)
            ans.push_back(root);
        return ans;
    }
};










