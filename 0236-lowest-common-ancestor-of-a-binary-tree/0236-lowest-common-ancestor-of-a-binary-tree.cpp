/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    TreeNode *solve(TreeNode *root,TreeNode *p,TreeNode *q)
    {
        if(root==NULL or root->val == p->val or root->val == q->val)
        {
            return root;
        }
        TreeNode *left = solve(root->left,p,q);
        TreeNode *right = solve(root->right,p,q);
        
        if(left==NULL)
        {
            return right;
        }
        else if(right==NULL)
        {
            return left;
        }
        return root;        //is both left and right is not equal to null
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root,p,q);
    }
};