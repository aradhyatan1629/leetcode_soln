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
    void dfs(TreeNode *root,int &sum,vector<int> &v,vector<vector<int>> &ans,int target)
    {
        if(root==NULL)
            return;
        sum += root->val;v.push_back(root->val);
        dfs(root->left,sum,v,ans,target);
        dfs(root->right,sum,v,ans,target);
        if(sum == target and (!root->left and !root->right))
        {
            ans.push_back(v);
        }
        sum -= root->val;
        v.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root==NULL)
            return {};
        vector<vector<int>> ans;
        int sum = 0;
        vector<int> v;
        dfs(root,sum,v,ans,targetSum);
        return ans;
    }
};