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
    
    void bfs(TreeNode *root,unordered_map<TreeNode*,TreeNode*> &parent)
    {
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
                    parent[node->left] = node;
                    q.push(node->left);
                }
                if(node->right)
                {
                    parent[node->right] = node;
                    q.push(node->right);
                }
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent;
        bfs(root,parent);
        
        unordered_map<TreeNode*,bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target]=true;
        int curr_level=0;
        
        while(!q.empty())
        {
            int sz = q.size();
            if(curr_level++ == k)
            {
                break;
            }
            for(int i=0;i<sz;i++)
            {
                TreeNode *node = q.front();
                q.pop();
                
                if(node->left and visited[node->left]==false)
                {
                    q.push(node->left);
                    visited[node->left] = true;
                }
                if(node->right and visited[node->right]==false)
                {
                    q.push(node->right);
                    visited[node->right] = true;
                }
                if(parent[node] and visited[parent[node]]==false)
                {
                    q.push(parent[node]);
                    visited[parent[node]] = true;
                }
            }
        }
        vector<int> ans;
        while(!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};