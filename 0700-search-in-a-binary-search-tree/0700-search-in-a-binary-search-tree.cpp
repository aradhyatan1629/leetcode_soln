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
    
    TreeNode* preorder(TreeNode *root,int val)
    {
        if(root==NULL)
        {
            return NULL;
        }
        else if(root->val == val)
        {
            return root;
        }
        else if(root->val > val)
        {
            return preorder(root->left,val);
        }
        else
        {
            return preorder(root->right,val);
        }
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL)
        {
            return NULL;
        }
        TreeNode *node = preorder(root,val);
        return node;
    }
};