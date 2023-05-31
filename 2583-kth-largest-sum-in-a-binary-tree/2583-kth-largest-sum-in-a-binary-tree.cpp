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
    
    void bfs(TreeNode *root,vector<long long> &v)
    {
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            long long sum = 0;
            int sz = q.size();
            
            for(int i=0;i<sz;i++)
            {
                TreeNode *node = q.front();
                q.pop();
                sum+=node->val;
                
                if(node->left)
                {
                    q.push(node->left);
                }
                if(node->right)
                {
                    q.push(node->right);
                }
            }
            v.push_back(sum);
        }
    } 
    
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> v;
        bfs(root,v);
        sort(v.begin(),v.end());
        if(v.size()<k)
        {
            return -1;
        }
        return v[v.size()-k];
    }
};