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
    
    vector<int> bfs(TreeNode *root)
    {
        if(root==NULL)
        {
            return {};
        }
        queue<TreeNode*> q;
        q.push(root);
        
        vector<int> ans;
        while(!q.empty())
        {
            int sz = q.size();
            TreeNode *temp = q.front();
            ans.push_back(temp->val);
            
            for(int i=0;i<sz;i++)
            {
                TreeNode *node = q.front();
                q.pop();
                
                if(node->right)
                {
                    q.push(node->right);
                }
                if(node->left)
                {
                    q.push(node->left);
                }
            }
        }
        return ans;
    }
    
    vector<int> rightSideView(TreeNode* root) {
        return bfs(root);
    }
};