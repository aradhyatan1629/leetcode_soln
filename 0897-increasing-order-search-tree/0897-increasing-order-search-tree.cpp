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
    
    void solve(TreeNode *root,int i,vector<int> &v)
    {
        while(root->right!=NULL and i<v.size())
        {
            if(root->left!=NULL)
            {
                root->left = NULL;
            }
            root->val = v[i];
            root = root->right;
            i++;
        }
        if(i<v.size())
        {
            root->val = v[i];
            i++;
        }
        while(i<v.size())
        {
            if(root->left!=NULL)
            {
                root->left = NULL;
            }
            TreeNode *n = new TreeNode();
            n->val = v[i];
            root->right = n;
            root=n;
            i++;
        }
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> v;
        inorder(root,v);
        TreeNode *t = root;
        solve(root,0,v);
        return t;
    }
};