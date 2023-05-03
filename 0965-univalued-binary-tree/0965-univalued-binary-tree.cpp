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
    
    bool inorder(TreeNode *root,int x)
    {
        if(root==NULL)
        {
            return true;
        }
        bool left = inorder(root->left,x);
        if(root->val!=x)
        {
            return false;
        }
        bool right = inorder(root->right,x);
        return (left and right);
    }
    bool isUnivalTree(TreeNode* root) {
        int x = root->val;
        return inorder(root,x);
    }
};