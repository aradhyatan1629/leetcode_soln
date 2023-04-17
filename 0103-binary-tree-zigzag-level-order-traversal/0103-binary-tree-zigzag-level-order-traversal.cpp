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
    
    //Solution without using reverse operation
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL)
        {
            return {};
        }
        
        bool flag=true;
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        q.push(root);
        
        while(!q.empty())
        {
            int size = q.size();
            vector<int> v(size);
            for(int i=0;i<size;i++)
            {
                TreeNode *node = q.front();
                q.pop();
                int index;
                
                if(flag)
                {
                    index = i;
                }
                else
                {
                    index = size-i-1;
                }
                v[index] = node->val;
                
                if(node->left!=NULL)
                {
                    q.push(node->left);
                }
                if(node->right!=NULL)
                {
                    q.push(node->right);
                }
            }
            flag=!flag;
            ans.push_back(v);
        }
        return ans;
    }
};