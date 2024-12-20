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
    
    bool flag = false;;
    
    void bfs(TreeNode *root)
    {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int sz = q.size();
            queue<TreeNode*> temp;
            vector<int> v;
            
            for(int i=0;i<sz;i++)
            {
                TreeNode *node = q.front();
                temp.push(node);
                v.push_back(node->val);
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
            if(flag)
            {
                int i=v.size()-1;
                while(!temp.empty())
                {
                    temp.front()->val = v[i--];
                    temp.pop();
                }
            }
            flag=!flag;
        }
    }
    
    TreeNode* reverseOddLevels(TreeNode* root) {
        bfs(root);
        return root;
    }
};