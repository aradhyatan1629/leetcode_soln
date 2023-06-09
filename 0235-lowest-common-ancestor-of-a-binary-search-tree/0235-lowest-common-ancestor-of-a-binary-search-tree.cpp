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
    bool getPath(TreeNode *root,TreeNode *node,vector<TreeNode*> &v)
    {
       if(root==NULL)
       {
           return false;
       }
       v.push_back(root);
       if(root->val == node->val)
       {
           return true;
       }
       if(getPath(root->left,node,v) or getPath(root->right,node,v))
       {
           return true;
       }
       v.pop_back();
       return false;
   }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> v1;
        vector<TreeNode*> v2;
        getPath(root,p,v1);
        getPath(root,q,v2);
        
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