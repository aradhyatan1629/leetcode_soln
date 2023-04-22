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
    
    void markParents(TreeNode *root,unordered_map<TreeNode*,TreeNode*> &m_parent)
    {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            if(node->left)
            {
                m_parent[node->left] = node;
                q.push(node->left);
            }
            if(node->right)
            {
                m_parent[node->right] = node;
                q.push(node->right);
            }
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> m_parent;
        markParents(root,m_parent);
        
        unordered_map<TreeNode*,bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int curr_level=0;
        
        while(!q.empty())
        {
            if(curr_level++==k)
            {
                break;
            }
            int size = q.size();
            for(int i=0;i<size;i++)
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
                if(m_parent[node] and visited[m_parent[node]]==false)
                {
                    q.push(m_parent[node]);
                    visited[m_parent[node]]=true;
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