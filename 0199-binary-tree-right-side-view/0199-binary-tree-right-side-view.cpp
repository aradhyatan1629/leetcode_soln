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
    vector<int> bfs(TreeNode *root)
    {
        queue<TreeNode*> q;
        vector<int> v;
        q.push(root);
            
        while(!q.empty())
        {
            int sz = q.size();
            v.push_back(q.front()->val);
            for(int i=0;i<sz;i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if(node->right)
                    q.push(node->right);
                if(node->left)
                    q.push(node->left);
            }
        }
        return v;
    }
    
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return {};
        vector<int> ans = bfs(root);
        return ans;
    }
};