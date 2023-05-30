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
    
    void inorder(TreeNode *root,vector<int> &v)
    {
        stack<TreeNode*> st;
        TreeNode *node = root;
        
        while(true)
        {
            if(node)
            {
                st.push(node);
                node=node->left;           //left
            }
            else
            {
                if(st.empty())
                {
                    break;
                }
                node=st.top();
                v.push_back(node->val);    //print
                st.pop();
                node=node->right;          //right
            }
        }
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root)
        {
            return {};
        }
        vector<int> v;
        inorder(root,v);
        return v;
    }
};