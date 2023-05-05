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
    
    int bfs(TreeNode *root,int level,int mxsum,int ans)
    {
        queue<TreeNode*> q;
        q.push(root);          
        while(!q.empty())
        {
            int sum=0;
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
            if(sum>mxsum)
            {
                mxsum = sum;
                ans = level;
            }
            level++;
        }
        return ans;
    }
    int maxLevelSum(TreeNode* root) {
        int level = 1;
        int mxsum = INT_MIN;
        int ans = 0;
        return bfs(root,level,mxsum,ans);
    }
};