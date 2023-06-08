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
    
    //T.c. - (logn)^2
    
    int findLeftHeight(TreeNode *node)
    {
        int h = 0;
        while(node)
        {
            h++;
            node=node->left;
        }
        return h;
    }
    
    int findRightHeight(TreeNode *node)
    {
        int h = 0;
        while(node)
        {
            h++;
            node=node->right;
        }
        return h;
    }
    
    int countNodes(TreeNode* root) {
        if(root==NULL)
        {
            return 0;
        }
        int leftH = findLeftHeight(root);
        int rightH = findRightHeight(root);
        
        if(leftH==rightH)
        {
            return pow(2,leftH) - 1;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};