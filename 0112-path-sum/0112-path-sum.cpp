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
    
    bool ans = false;
    int sum = 0;
    
    void dfs(TreeNode *root,int targetSum)
    {
        if(root==NULL)
        {
            return;
        }
        sum+=root->val;
        dfs(root->left,targetSum);
        dfs(root->right,targetSum);
        if((root->left==NULL and root->right==NULL) and sum == targetSum)
        {
            ans=true;
        }
        sum-=root->val;
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL)
        {
            return false;
        }
        if(root->left==NULL and root->right==NULL)
        {
            if(root->val == targetSum)
            {
                return true;
            }
            return false;
        }
        dfs(root,targetSum);
        return ans;
    }
};