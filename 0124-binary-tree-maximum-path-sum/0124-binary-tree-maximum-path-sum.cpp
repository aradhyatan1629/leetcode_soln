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
    int ans=INT_MIN;
    int maxPath(TreeNode *node)
    {
        if(node==NULL)
        {
            return 0;
        }
        int leftSum = maxPath(node->left);
        int rightSum = maxPath(node->right);
        
        ans = max(ans,node->val+leftSum+rightSum);
        return max(0,max(leftSum,rightSum) + node->val);
    }
    int maxPathSum(TreeNode* root) {
        maxPath(root);
        return ans;
    }
};