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
    int height(TreeNode *root)
    {
        if(root==NULL)
            return 0;
        int leftH = height(root->left);
        int rightH = height(root->right);
        if(leftH == -1 or rightH == -1)
            return -1;
        if(abs(leftH-rightH) > 1)
            return -1;
        return 1 + max(leftH,rightH);
    }
    
    bool isBalanced(TreeNode* root) {
        return height(root)!=-1;
    }
};