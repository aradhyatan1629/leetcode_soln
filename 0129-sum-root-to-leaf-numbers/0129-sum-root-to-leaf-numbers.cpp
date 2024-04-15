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
    void solve(TreeNode *root,int n,int &sum)
    {
        if(root==NULL)
            return;
        n = n*10 + root->val;
        solve(root->left,n,sum);
        solve(root->right,n,sum);
        if(!root->left && !root->right)
            sum += n;
    }
    
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        solve(root,0,sum);
        return sum;
    }
};