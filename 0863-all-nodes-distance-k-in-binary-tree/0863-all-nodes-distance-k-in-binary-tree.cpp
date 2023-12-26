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
    //convert the tree to undirected graph and then do simple bfs on the graph
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> adj[501];
        queue<TreeNode*> q;
        
        q.push(root);
        
        while(!q.empty())  // creating adjacency list
        {
            int sz = q.size();
            for(int i=0;i<sz;i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if(node->left)
                {
                    q.push(node->left);
                    adj[node->val].push_back(node->left->val);
                    adj[node->left->val].push_back(node->val);
                }
                if(node->right)
                {
                    q.push(node->right);
                    adj[node->val].push_back(node->right->val);
                    adj[node->right->val].push_back(node->val);
                }
            }
          
        }
        
        queue<pair<int,int>> q1;
        vector<int> vis(500,0),ans;
        
        vis[target->val] = 1;
        q1.push({target->val,0});
        
        while(!q1.empty())  //bfs traversal on graph
        {
            int node = q1.front().first;
            int level = q1.front().second;
            if(level == k)
                ans.push_back(node);
            q1.pop();
            for(auto it:adj[node])
            {
                if(!vis[it])
                {
                    vis[it]=1;
                    q1.push({it,level+1});
                }
            }
        }
        return ans;
    }
};