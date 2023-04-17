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
    
    bool solve(TreeNode *nodeLeft,TreeNode *nodeRight)
    {
        if(nodeLeft==NULL or nodeRight==NULL)
        {
            return nodeLeft==nodeRight;
        }
        if(nodeLeft->val!=nodeRight->val)
        {
            return false;
        }
        return solve(nodeLeft->left,nodeRight->right) 
               and solve(nodeLeft->right,nodeRight->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
        {
            return true;
        }
        return solve(root->left,root->right);
    }
};