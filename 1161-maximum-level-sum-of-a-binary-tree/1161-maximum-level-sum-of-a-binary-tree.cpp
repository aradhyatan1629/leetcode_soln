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
    int maxLevelSum(TreeNode* root) {
        int ans = INT_MAX,level=1;
        long long mxSum = INT_MIN;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int sz = q.size();
            long long sum = 0;
            for(int i=0;i<sz;i++)
            {
                TreeNode *node = q.front();q.pop();
                sum += node->val;
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            if(sum > mxSum){ans = level;mxSum = sum;}
            level++;
        }
        ans = (ans == INT_MAX) ? 0 : ans;
        return ans;
    }
};