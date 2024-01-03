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
    unordered_map<string,int> flag;
    string solve(TreeNode *root,unordered_map<string,int> &m,vector<TreeNode*> &ans)
    {
        if(root==NULL)
            return "#";
        string left = solve(root->left,m,ans);
        string right = solve(root->right,m,ans);
        string s = left + "," + right + "," + to_string(root->val);
        if(m[s] == 1)
            ans.push_back(root);
        m[s]++;
        return s;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,int> m;   // to serialize the subtree
        vector<TreeNode*> ans;
        solve(root,m,ans);
        return ans;
    }
};