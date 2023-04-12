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
    //Brute Force - O(n^2)
    int ans=0;
    int height(TreeNode *root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int leftH = height(root->left);
        int rightH = height(root->right);
        return 1+max(leftH,rightH);
    }
    
    void solve(TreeNode *root)
    {
        if(root==NULL)
        {
            return;
        }
        int leftH = height(root->left);
        int rightH = height(root->right);
        ans = max(ans,leftH+rightH);
        solve(root->left);
        solve(root->right);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        solve(root);
        return ans;
    }
};