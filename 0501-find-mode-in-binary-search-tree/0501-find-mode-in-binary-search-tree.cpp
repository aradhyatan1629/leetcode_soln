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
    
    void inorder(TreeNode *root,unordered_map<int,int> &m,vector<int> &ans)
    {
        if(root==NULL)
        {
            return;
        }
        inorder(root->left,m,ans);
        m[root->val]++;
        inorder(root->right,m,ans);
        
        
    }
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> m;
        vector<int> ans;
        inorder(root,m,ans);
        
        int mx = 0;
        for(auto x:m)
        {
            mx = max(mx,x.second);
        }
        for(auto x:m)
        {
            if(x.second==mx)
            {
                ans.push_back(x.first);
            }
        }
        
        return ans;
    }
};