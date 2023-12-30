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
    int solve(TreeNode *root,int &mx)
    {
        if(root==NULL)
            return 0;
        int leftH = solve(root->left,mx);
        int rightH = solve(root->right,mx);
        mx = max(mx,leftH+rightH);
        return 1+max(leftH,rightH);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int mx = 0;
        solve(root,mx);
        return mx;
    }
};