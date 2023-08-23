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
    //Soln using reverse preorder traversal
    
    void preorder(TreeNode *root,int lvl,vector<int> &v)
    {
        if(root==NULL)
        {
            return;
        }
        if(lvl == v.size())         //This is the first time we came across this level
        {
            v.push_back(root->val);
        }
        preorder(root->right,lvl+1,v);
        preorder(root->left,lvl+1,v);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL)
        {
            return {};
        }
        vector<int> v;
        preorder(root,0,v);
        return v;
    }
};