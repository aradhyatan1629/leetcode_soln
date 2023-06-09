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
    //O(nlogn) and O(n) soln
    
    void dfs(TreeNode *root,vector<int> &v)
    {
        if(root==NULL)
        {
            return;
        }
        dfs(root->left,v);
        v.push_back(root->val);
        dfs(root->right,v);
    }
    
    void solve(TreeNode *root,vector<int> &v,int &i)
    {
        if(root==NULL)
        {
            return;
        }
        solve(root->left,v,i);
        if(root->val != v[i])
        {
            root->val = v[i];
        }
        i++;
        solve(root->right,v,i);
    }
    
    void recoverTree(TreeNode* root) {
        vector<int> v;
        int i = 0;
        dfs(root,v);
        sort(v.begin(),v.end());
        solve(root,v,i);
    }
};