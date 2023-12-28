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
    
    void solve(TreeNode *root,unordered_map<string,int> &m,string &s)
    {
        if(root==NULL)
            return;
        s += char(root->val+97);
        solve(root->left,m,s);
        solve(root->right,m,s);
        if(root->left==NULL and root->right==NULL)
            m[s]++;
        s.pop_back();
    }
    
    string smallestFromLeaf(TreeNode* root) {
        unordered_map<string,int> m;
        string s,ans;
        solve(root,m,s);
        
        for(auto x:m)
        {
            string t = x.first;
            reverse(t.begin(),t.end());
            if(t<ans or ans=="")ans=t;
        }
        return ans;
    }
};