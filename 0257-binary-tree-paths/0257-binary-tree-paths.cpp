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
    vector<string> ans;
    
    void preorder(TreeNode *node,string s)
    {
        if(node->left==NULL and node->right==NULL)
        {
            s+=to_string(node->val);
            ans.push_back(s);
            return;
        }
        s+=to_string(node->val) + "->";
        if(node->left)
        {
            preorder(node->left,s);
        }
        if(node->right)
        {
            preorder(node->right,s);
        }
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root==NULL)
        {
            return {};
        }
        preorder(root,"");
        return ans;
    }
};