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
    // O(n) O(n) striver soln
    
    TreeNode *prev;
    TreeNode *violation1;
    TreeNode *violation2;
    
    
    void inorder(TreeNode *root)
    {
        if(root==NULL)
        {
            return;
        }
        inorder(root->left);
        if(prev!=NULL and prev->val>root->val)
        {
            if(violation1==NULL)
            {
               violation1 = prev;
            }
            violation2 = root;
        }
        prev = root;
        inorder(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        inorder(root);
        int t = violation1->val;
        violation1->val = violation2->val;
        violation2->val = t;
    }
};