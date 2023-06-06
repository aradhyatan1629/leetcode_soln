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
    
    //bfs soln - 
    
    bool bfs(TreeNode *root)
    {
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        
        while(!q.empty())
        {
            TreeNode *leftNode = q.front();
            q.pop();
            TreeNode *rightNode = q.front();
            q.pop();
            
            if(leftNode==NULL and rightNode==NULL)
            {
                continue;
            }
            if(leftNode==NULL or rightNode==NULL or leftNode->val!=rightNode->val)
            {
                return false;
            }
            q.push(leftNode->left);
            q.push(rightNode->right);
            q.push(leftNode->right);
            q.push(rightNode->left);
        }
        return true;
    }
    
    bool isSymmetric(TreeNode* root) {
        return bfs(root);
    }
};