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
    
    bool path(TreeNode *root,vector<TreeNode*> &v,TreeNode *target)
    {
        if(root==NULL)
        {
            return false;
        }
        v.push_back(root);
        if(root==target)
        {
            return true;
        }
        if(path(root->left,v,target) or path(root->right,v,target))
        {
            return true;
        }
        v.pop_back();
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> v1,v2;
        path(root,v1,p);
        path(root,v2,q);
        int i=0,j=0;
        while(i<v1.size() and j<v2.size())
        {
            if(v1[i]!=v2[j])
            {
                break;
            }
            i++;
            j++;
        }
        return v1[i-1];
    }
};