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
    
    int xDepth,yDepth,xParent,yParent;
    void solve(TreeNode *root,int x,int y,int depth,int parent)
    {
        if(root==NULL)
            return;
        
        if(root->val == x)
        {
            xDepth = depth;
            xParent = parent;
        }
        if(root->val == y)
        {
            yDepth = depth;
            yParent = parent;
        }
        solve(root->left,x,y,depth+1,root->val);
        solve(root->right,x,y,depth+1,root->val);
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        solve(root,x,y,0,-1);
        if(xDepth != yDepth or xParent == yParent)
            return false;
        return true;
    }
};