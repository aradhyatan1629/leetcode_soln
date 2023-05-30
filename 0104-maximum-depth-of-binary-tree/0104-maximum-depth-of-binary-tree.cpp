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
        queue<TreeNode*> q;
        q.push(root);
        int lvl = 0;
        
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
                }
                if(node->right)
                {
                    q.push(node->right);
                }
            }
            lvl++;
        }
        return lvl;
    }
    
    int maxDepth(TreeNode* root) {
        if(!root)
        {
            return 0;
        } 
        return bfs(root);
    }
};