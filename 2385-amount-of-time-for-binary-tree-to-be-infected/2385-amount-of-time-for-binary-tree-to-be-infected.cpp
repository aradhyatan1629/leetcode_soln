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
    void dfs(TreeNode *root,unordered_map<int,vector<int>> &m)
    {
        if(root==NULL)
            return;
        if(root->left)
        {
            m[root->val].push_back(root->left->val);
            m[root->left->val].push_back(root->val);
        }
        dfs(root->left,m);
        if(root->right)
        {
            m[root->val].push_back(root->right->val);
            m[root->right->val].push_back(root->val);
        }
        dfs(root->right,m);
    }
    
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,vector<int>> m;
        dfs(root,m);
        
        int ans = 0;
        unordered_map<int,int> vis;
        queue<pair<int,int>> q;
        vis[start]=1;
        q.push({start,0});
        while(!q.empty())
        {
            int node = q.front().first;
            int time = q.front().second;
            q.pop();
            ans = max(ans,time);
            for(auto it:m[node])
            {
                if(vis[it]!=1)
                {
                    vis[it]=1;
                    q.push({it,time+1});
                }
            }
        }
        return ans;
    }
};