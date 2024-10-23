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
    void solve(TreeNode *root,int p,int depth,unordered_map<int,pair<int,int>> &m){
        if(root == NULL){
            return;
        }
        m[root->val] = {p,depth};
        solve(root->left,root->val,depth+1,m);
        solve(root->right,root->val,depth+1,m);
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        unordered_map<int,pair<int,int>> m; //{node,{parent,depth}}
        solve(root,-1,0,m);
        
        if(m[x].second == m[y].second && m[x].first != m[y].first)
            return true;
        return false;
    }
};