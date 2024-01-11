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
    pair<int,int> solve(TreeNode *root,int &ans)
    {
        if(root==NULL)
            return {INT_MIN,INT_MAX};
        
        pair<int,int> left = solve(root->left,ans);
        pair<int,int> right = solve(root->right,ans);
    
        int mx = max(root->val,max(left.first,right.first));
        int mn = min(root->val,min(left.second,right.second));
        ans = max(ans,abs(root->val-mn));
        ans = max(ans,abs(root->val-mx));
        return {mx,mn};
    }
    
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        solve(root,ans);
        return ans;
    }
};