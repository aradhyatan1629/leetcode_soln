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
    unordered_map<int,int> m;
    bool check(unordered_map<int,int> &m)
    {
        int t=0;
        for(auto x:m)
            if(x.second%2!=0)
                t++;
        if(t>1)
            return false;
        return true;
    }
    
    void dfs(TreeNode *root,int &cnt)
    {
        if(root==NULL)
            return;
        m[root->val]++;
        dfs(root->left,cnt);
        dfs(root->right,cnt);
        if(root->left==NULL and root->right==NULL)
        {
            if(check(m))
                cnt++;
        }
        m[root->val]--;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        int cnt=0;
        dfs(root,cnt);
        return cnt;
    }
};