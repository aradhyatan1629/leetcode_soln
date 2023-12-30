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
    bool getPath(TreeNode *root,int target,vector<TreeNode*> &v)
    {
        if(root==NULL)
            return false;
        v.push_back(root);
        if(root->val == target)
            return true;
        bool left = getPath(root->left,target,v);
        bool right = getPath(root->right,target,v);
        if(left or right)
            return true;
        v.pop_back();
        return false;
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        vector<TreeNode*> v1,v2;
        getPath(root,x,v1);
        getPath(root,y,v2);
        if(v1.size()<=1 or v2.size()<=1 or v1.size()!=v2.size())
            return false;
        if(v1[v1.size()-2]->val == v2[v2.size()-2]->val)
            return false;
        return true;
    }
};