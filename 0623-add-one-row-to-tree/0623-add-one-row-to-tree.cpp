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
            TreeNode *node = new TreeNode(val);
            node->left = root;root=node;
            return root;
        }
        int d = 1;
        queue<TreeNode*> q;
        q.push(root);
        
        while(d+1!=depth)
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
            TreeNode *node = q.front();q.pop();
            TreeNode *node1 = new TreeNode(val);TreeNode *node2 = new TreeNode(val);
            node1->left = node->left;node2->right = node->right;
            node->left=node1;node->right=node2;
        }
        return root;
    }
};