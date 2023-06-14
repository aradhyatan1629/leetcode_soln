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
    //O(n) and O(1)
    
    void inorder(TreeNode *root,int &ans,int &prev)
    {
        if(root==NULL)
        {
            return;
        }
        inorder(root->left,ans,prev);
        if(prev!=-1)
        {
            ans = min(ans,root->val-prev);
        }
        prev = root->val;
        inorder(root->right,ans,prev);
    }
    
    int getMinimumDifference(TreeNode* root) {
        int ans=INT_MAX,prev=-1;
        inorder(root,ans,prev);
        return ans;
    }
};