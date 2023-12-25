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
    
    void preorder(TreeNode *root,vector<string> &ans,string s)
    {
        if(!root)
            return;
        s+=to_string(root->val);s+="->";
        preorder(root->left,ans,s);
        preorder(root->right,ans,s);
        if(root->left==NULL and root->right==NULL)
        {
            s.pop_back();s.pop_back();ans.push_back(s);
        }
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root)
            return {};
        vector<string> ans;
        string s;
        preorder(root,ans,s);
        return ans;
    }
};