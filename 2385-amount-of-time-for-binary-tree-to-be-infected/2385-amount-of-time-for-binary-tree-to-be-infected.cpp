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
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,vector<int>> m;   //adjacency list {node,{neighbours}}
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int sz = q.size();
            for(int i=0;i<sz;i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if(node->left)
                {
                    q.push(node->left);
                    m[node->val].push_back(node->left->val);
                    m[node->left->val].push_back(node->val);
                }
                if(node->right)
                {
                    q.push(node->right);
                    m[node->val].push_back(node->right->val);
                    m[node->right->val].push_back(node->val);
                }
            }
        }
        unordered_map<int,int> vis;
        queue<pair<int,int>> q1;
        q1.push({start,0});
        vis[start]=1;
        int ans=0;
        
        while(!q1.empty())
        {
            int node = q1.front().first;
            int time = q1.front().second;
            ans = max(ans,time);
            q1.pop();
            
            for(auto it:m[node])
            {
                if(!vis[it])
                {
                    vis[it]=1;
                    q1.push({it,time+1});
                }
            }
        }
        return ans;
        
    }
};