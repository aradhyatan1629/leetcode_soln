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
            return {INT_MAX,INT_MIN};
        
        pair<int,int> pLeft = solve(root->left,ans);
        pair<int,int> pRight = solve(root->right,ans);
        int mn = min(root->val,min(pLeft.first,pRight.first));
        int mx = max(root->val,max(pLeft.second,pRight.second));
        if(mn!=root->val or mx!=root->val)
        {
            ans = max(ans,abs(root->val-mn));
            ans = max(ans,abs(root->val-mx));
        }
        return {mn,mx};
    }
    
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        solve(root,ans);
        return ans;
    }
};