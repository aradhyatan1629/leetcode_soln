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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
            return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        
        bool flag = true;
        
        while(!q.empty())
        {
            int sz = q.size();
            vector<int> v(sz,0);
            for(int i=0;i<sz;i++)
            {
                TreeNode *node = q.front();
                q.pop();
                
                if(flag)v[i]=node->val;
                else v[sz-i-1]=node->val;
                
                if(node->left)
                {
                    q.push(node->left);
                }
                if(node->right)
                {
                    q.push(node->right);
                }
            }
            ans.push_back(v);
            flag=!flag;
        }
        return ans;
    }
};