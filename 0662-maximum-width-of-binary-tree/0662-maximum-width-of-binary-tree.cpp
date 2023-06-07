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
    
    int bfs(TreeNode *root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int ans = 0;
        queue<pair<TreeNode*,int>> q;   //{node,index}
        q.push({root,0});
        
        while(!q.empty())
        {
            int sz = q.size();
            int mn_index = q.front().second;      //min index on each level (not always 1)
            int first_index,last_index;
            
            for(int i=0;i<sz;i++)
            {
                int curr_index = q.front().second - mn_index;
                TreeNode *node = q.front().first;
                q.pop();
                
                if(i==0)
                {
                    first_index = curr_index;
                }
                if(i==sz-1)
                {
                    last_index = curr_index;
                }
                
                if(node->left)
                {
                    q.push({node->left,(long long)curr_index*2+1});
                }
                if(node->right)
                {
                    q.push({node->right,(long long)curr_index*2+2});
                }
            }
            ans = max(ans,last_index-first_index+1);
        }
        return ans;
    }
    
    int widthOfBinaryTree(TreeNode* root) {
        return bfs(root);
    }
};