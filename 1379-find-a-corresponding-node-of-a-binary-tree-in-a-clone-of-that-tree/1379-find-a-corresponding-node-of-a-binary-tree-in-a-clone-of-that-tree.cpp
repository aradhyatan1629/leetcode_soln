/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    
    TreeNode *ans = NULL;
    TreeNode* dfs(TreeNode *root,TreeNode *target)
    {
        if(root==NULL)
        {
            return NULL;
        }
        dfs(root->left,target);
        if(root->val == target->val)
        {
            ans=root;
        }
        dfs(root->right,target);
        return ans;
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return dfs(cloned,target);
    }
};