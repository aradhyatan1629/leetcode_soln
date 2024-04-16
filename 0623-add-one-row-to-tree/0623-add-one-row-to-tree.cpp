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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1)
        {
            TreeNode *newNode = new TreeNode(val);
            newNode->left = root;
            root = newNode;
            return root;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        int d = 1;
        while(!q.empty() && d<depth-1)
        {
            int sz = q.size();
            for(int i=0;i<sz;i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            d++;
        }
        while(!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            TreeNode *leftC = new TreeNode(val);TreeNode *rightC = new TreeNode(val);
            leftC->left = node->left;node->left=leftC;
            rightC->right = node->right;node->right=rightC;
        }
        return root;
    }
};