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
    
    long long lastVal = LONG_MIN;
    bool ans = true;
    
    void inorder(TreeNode *root)
    {
        if(root==NULL)
        {
            return;
        }
        inorder(root->left);
        if(lastVal < root->val)
        {
            lastVal = root->val;
        }
        else
        {
            ans = false;
            return;
        }
        inorder(root->right);
    }
    
    bool isValidBST(TreeNode* root) {
        inorder(root);
        return ans;
    }
};