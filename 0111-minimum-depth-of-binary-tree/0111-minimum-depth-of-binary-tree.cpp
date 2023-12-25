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
    int mnDepth(TreeNode *root)
    {
        if(root==NULL)
            return 0;
        int left = mnDepth(root->left);
        int right = mnDepth(root->right);
        if(left!=0 and right!=0)
            return 1+min(left,right);
        return 1+max(left,right);
    }
    
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        return mnDepth(root);
    }
};