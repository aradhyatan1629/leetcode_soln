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
    void solve(TreeNode *root,string curr,string &ans)
    {
        if(root==NULL)
            return;
        char ch = char(root->val + 'a');
        curr = ch + curr;
        if(root->left==NULL && root->right==NULL)
        {
            if(ans=="" || curr<ans)
                ans = curr;
        }
        solve(root->left,curr,ans);
        solve(root->right,curr,ans);
    }
    
    string smallestFromLeaf(TreeNode* root) {
        string ans = "";
        string curr = "";
        solve(root,curr,ans);
        return ans;
    }
};