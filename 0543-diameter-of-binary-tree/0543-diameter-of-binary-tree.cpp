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
    int ans=0;
    int height(TreeNode *node)
    {
        if(node==NULL)
        {
            return 0;
        }
        int leftH = height(node->left);
        int rightH = height(node->right);
        return 1+max(leftH,rightH);
    }
    void solve(TreeNode *node)
    {
        if(node==NULL)
        {
            return;
        }
        int leftH = height(node->left);
        int rightH = height(node->right);
        ans = max(ans,leftH+rightH);
        solve(node->left);
        solve(node->right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        solve(root);
        return ans;
    }
};