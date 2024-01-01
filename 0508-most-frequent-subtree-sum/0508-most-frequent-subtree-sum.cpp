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
    int solve(TreeNode *root,unordered_map<int,int> &m)
    {
        if(root==NULL)
            return 0;
        
        int leftSum = solve(root->left,m);
        int rightSum = solve(root->right,m);
        int totalSum = root->val + leftSum + rightSum;
        m[totalSum]++;
        return totalSum;
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int> m;
        solve(root,m);
        int mx = 0;
        for(auto x:m)
            mx = max(mx,x.second);
        
        vector<int> ans;
        for(auto x:m)
            if(x.second==mx)
                ans.push_back(x.first);
        
        return ans;
    }
};