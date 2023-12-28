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
    
    int mx=INT_MIN;
    int height(TreeNode *root,int &ans)
    {
        if(root==NULL)
            return 0;
        int leftH = height(root->left,ans);
        int rightH = height(root->right,ans);
        ans = max(ans,leftH+rightH);
        return 1 + max(leftH,rightH);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 0;
        int ans=0;
        height(root,ans);
        return ans;
    }
};