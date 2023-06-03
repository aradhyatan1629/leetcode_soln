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
    
    void inorder(TreeNode *root,vector<int> &v)
    {
        if(root==NULL)
        {
            return;
        }
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    
    int i=0;
    void solve(TreeNode *root,vector<int> &v,int n)
    {
        if(root==NULL)
        {
            return;
        }
        solve(root->left,v,n);
        if(i==0)
        {
            root->val = v[n-1];
        }
        else 
        {
            root->val = v[n-1] - v[i-1];
        }
        i++;
        solve(root->right,v,n);
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        vector<int> v;
        inorder(root,v);
        for(int i=1;i<v.size();i++)
        {
            v[i]=v[i]+v[i-1];
        }
        solve(root,v,v.size());
        return root;
    }
};
