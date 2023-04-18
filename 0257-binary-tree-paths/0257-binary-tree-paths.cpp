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
    vector<vector<int>> ans;
    vector<int> v;
    
    void preorder(TreeNode *node)
    {
        if(node->left==NULL and node->right==NULL)
        {
            v.push_back(node->val);
            ans.push_back(v);
            v.pop_back();
            return;
        }
        v.push_back(node->val);
        if(node->left!=NULL)
        {
            preorder(node->left);
        }
        if(node->right!=NULL)
        {
            preorder(node->right);
        }
        v.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root==NULL)
        {
            return {};
        }
        preorder(root);
        vector<string> res;
        for(auto x:ans)
        {
            string s;
            for(auto y:x)
            {
                s+=to_string(y);
                s+="->";
            }
            s.pop_back();
            s.pop_back();
            res.push_back(s);
        }
        return res;
    }
};