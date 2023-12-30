/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool getPath(TreeNode *root,TreeNode *target,vector<TreeNode*> &v)
    {
        if(root==NULL)
            return false;
        v.push_back(root);
        if(root->val == target->val)
            return true;
        bool left = getPath(root->left,target,v);
        bool right = getPath(root->right,target,v);
        if(left or right)
            return true;
        v.pop_back();
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> v1,v2;
        getPath(root,p,v1);
        getPath(root,q,v2);
        int i=0,j=0;
        while(i<v1.size() and j<v2.size())
        {
            if(v1[i]!=v2[j])
                break;
            i++,j++;
        }
        return v1[i-1];
    }
};