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
    void solve(TreeNode *root,vector<int> &pre,int &ind,int n)
    {
        if(root==NULL)
            return;
        solve(root->left,pre,ind,n);
        if(ind==0){
            root->val = pre[n-1];
        }
        else{
            root->val = pre[n-1] - pre[ind-1];
        }
        ind++;
        solve(root->right,pre,ind,n);
    }
    
    void inorder(TreeNode *root,vector<int> &v)
    {
        if(root==NULL)
            return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        vector<int> v;
        inorder(root,v);
        int n = v.size();
        vector<int> pre(n,0);
        pre[0] = v[0];
        for(int i=1;i<n;i++)
            pre[i] = pre[i-1] + v[i];
        
        int ind = 0;
        solve(root,pre,ind,n);
        return root;
    }
};


/*
0 1 2 3 4 5 6 7 8
0 1 3 6 10 15 21 28 36

*/