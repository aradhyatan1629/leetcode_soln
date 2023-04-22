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
    
    void markParents(TreeNode *root,unordered_map<TreeNode*,TreeNode*> &parent_track)
    {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode *node = q.front();
                q.pop();
                
                if(node->left)
                {
                    parent_track[node->left] = node;
                    q.push(node->left);
                }
                if(node->right)
                {
                    parent_track[node->right] = node;
                    q.push(node->right);
                }
            }
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent_track; //node->parent
        markParents(root,parent_track);
        
        unordered_map<TreeNode*,bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int current_level = 0;
        
        while(!q.empty()) //second bfs to go upto k level from our target and using our hashtable info
        {
            int size = q.size();
            if(current_level++==k)
            {
                break;
            }
            for(int i=0;i<size;i++)
            {
                TreeNode *current = q.front();
                q.pop();
                
                if(current->left and visited[current->left]==false)
                {
                    q.push(current->left);
                    visited[current->left]=true;
                }
                if(current->right and visited[current->right]==false)
                {
                    q.push(current->right);
                    visited[current->right]=true;
                }
                if(parent_track[current] and visited[parent_track[current]]==false)
                {
                    q.push(parent_track[current]);
                    visited[parent_track[current]] = true;
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