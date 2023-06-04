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
    
    
    void preorder(TreeNode *root,int level,vector<int> &ans)
    {
        if(root==NULL)
        {
            return;
        }
        if(level<ans.size())
        {
            if(root->val>ans[level])
            {
                ans[level] = root->val;
            }
        }
        else
        {
            ans.push_back(root->val);
        }
        preorder(root->left,level+1,ans);
        preorder(root->right,level+1,ans);
    }
    
    vector<int> largestValues(TreeNode* root) {
        vector<int> v;
        preorder(root,0,v);
        return v;
    }
};