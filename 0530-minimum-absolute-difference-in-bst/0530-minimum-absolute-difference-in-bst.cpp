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
    
    int getMinimumDifference(TreeNode* root) {
        vector<int> v;
        inorder(root,v);
        int mn = INT_MAX;
        for(int i=0;i<v.size()-1;i++)
        {
            for(int j=i+1;j<v.size();j++)
            {
                mn = min(mn,abs(v[i]-v[j]));
            }
        }
        return mn;
    }
};