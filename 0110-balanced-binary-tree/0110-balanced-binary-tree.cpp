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
    //O(n) using the postorder traversal
    int solve(TreeNode *root)
    {
        if(root==NULL)
            return 0;
        int leftH = solve(root->left);
        int rightH = solve(root->right);
        if(leftH==-1 or rightH==-1)
            return -1;
        if(abs(leftH-rightH)>1)
            return -1;
        return 1+max(leftH,rightH);
    }
    
    bool isBalanced(TreeNode* root) {
        return solve(root)!=-1;
    }
};