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
    
    void bfs(TreeNode *root,vector<vector<int>> &ans)
    {
        queue<TreeNode*> q;
        q.push(root);
        bool flag = false;
        while(!q.empty())
        {
            vector<int> v;
            int sz = q.size();
            for(int i=0;i<sz;i++)
            {
                TreeNode *node = q.front();
                q.pop();
                v.push_back(node->val);
                if(node->left)
                {
                    q.push(node->left);
                }
                if(node->right)
                {
                    q.push(node->right);
                }
            }
            if(flag)
            {
                reverse(v.begin(),v.end());
                ans.push_back(v);
            }
            else
            {
                ans.push_back(v);
            }
            flag=!flag;
        }
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL)
        {
            return {};
        }
        vector<vector<int>> ans;
        bfs(root,ans);
        return ans;
    }
};