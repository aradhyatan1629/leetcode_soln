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
    
    int lvl = 0;
    bool bfs(TreeNode *root)
    {
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int sz = q.size();
            int prev_odd = INT_MIN , prev_even = INT_MAX;
            
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
                
                if(lvl%2==0 and node->val%2!=0 and node->val>prev_odd)
                {
                    prev_odd = node->val;
                }
                else if(lvl%2!=0 and node->val%2==0 and node->val<prev_even)
                {
                    prev_even = node->val;
                }
                else
                {
                    return false;
                }
            }
            lvl++;
            
        }
        return true;
    }
    
    bool isEvenOddTree(TreeNode* root) {
        return bfs(root);
    }
};