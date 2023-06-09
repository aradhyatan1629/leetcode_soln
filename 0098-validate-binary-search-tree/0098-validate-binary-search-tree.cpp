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
    
    //Striver approach (using range)
    
    bool isBST(TreeNode *root,long mnVal,long mxVal)
    {
        if(root==NULL)
        {
            return true;
        }
        if(root->val >= mxVal or root->val <= mnVal)
        {
            return false;
        }
        return isBST(root->left,mnVal,root->val) and isBST(root->right,root->val,mxVal);
    }
    
    bool isValidBST(TreeNode* root) {
        return isBST(root,LONG_MIN,LONG_MAX);
    }
};