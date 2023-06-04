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
    
    
    int count(TreeNode *root,int &cnt)
    {
        if(root==NULL)
        {
            return 0;
        }
        count(root->left,cnt);
        cnt++;
        count(root->right,cnt);
        return cnt;
    }
    
    int sum(TreeNode *root,int &s)
    {
        if(root==NULL)
        {
            return 0;
        }
        sum(root->left,s);
        s+=root->val;
        sum(root->right,s);
        return s;
    }
    
    int ans=0;
    void solve(TreeNode *root)
    {
        if(root==NULL)
        {
            return;
        }
        int s = 0,c=0;
        s = sum(root,s);
        c = count(root,c);
        if(s/c==root->val)
        {
            ans++;
        }
        solve(root->left);
        solve(root->right);
    }
    
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return ans;
    }
};