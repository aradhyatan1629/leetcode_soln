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
    
    
    void preorder(TreeNode *root,vector<int> &v)
    {
        if(root==NULL)
        {
            return;
        }
        v.push_back(root->val);
        preorder(root->left,v);
        preorder(root->right,v);
    }
    
    void flatten(TreeNode* root) {
        vector<int> v;
        preorder(root,v);
        if(v.size()==0 or v.size()==1)
        {
            return;
        }
        
        TreeNode *node = root;
        TreeNode *prev = node;
        root->left=NULL;
        int i=0;
        
        while(i<v.size())
        {
            if(node and node->val == v[i])
            {
                prev=node;
                node->left=NULL;
                node=node->right;
            }
            else if(node and node->val!=v[i])
            {
                prev=node;
                node->left=NULL;
                node->val=v[i];
                node=node->right;
            }
            else if(node==NULL)
            {
                TreeNode *t = new TreeNode();
                t->val = v[i];
                prev->right = t;
                node=t;
                prev=node;
                node=node->right;
            }
            i++;
        }
    }
};