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
    void solve(TreeNode *root,int &sum)
    {
        // cout<<root->val<<endl;
        if(root==NULL)
            return;
        if((root->left and root->left->left) and root->val%2==0)
            sum+=root->left->left->val;
        if((root->right and root->right->right) and root->val%2==0)
            sum+=root->right->right->val;
        if((root->left and root->left->right) and root->val%2==0)
            sum+=root->left->right->val;
        if((root->right and root->right->left) and root->val%2==0)
            sum+=root->right->left->val;
        
        solve(root->left,sum);
        solve(root->right,sum);
    }
    
    int sumEvenGrandparent(TreeNode* root) {
        int sum = 0;
        solve(root,sum);
        return sum;
    }
};