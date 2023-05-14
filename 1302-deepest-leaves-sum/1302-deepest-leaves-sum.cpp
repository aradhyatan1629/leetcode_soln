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
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int sz = q.size();
            int sum=0;
            for(int i=0;i<sz;i++)
            {
                TreeNode *node = q.front();
                sum+=node->val;
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
            ans = sum;
            sum=0;
        }
        return ans;
    }
    
    int deepestLeavesSum(TreeNode* root) {
        return bfs(root);
    }
};