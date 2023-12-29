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
    int findLeftHeight(TreeNode *node)
    {
        int height = 0;
        while(node)
        {
            height++;
            node = node->left;
        }
        return height;
    }
    int findRightHeight(TreeNode *node)
    {
        int height = 0;
        while(node)
        {
            height++;
            node = node->right;
        }
        return height;
    }
    
    int countNodes(TreeNode* root) {
        if(root==NULL)
            return 0;
        int leftH = findLeftHeight(root);
        int rightH = findRightHeight(root);
        
        if(leftH == rightH)     
            return pow(2,leftH)-1;
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};


/*

If leftHeight == rightHeight, then the last level nodes are completely filled
and hence it is a perfect binary tree so we can use the formulae 2^h -1 to get the total
number of nodes where h is the height of subtree

If leftHeight != rightHeight, then the last level nodes are not completely filled
when leftHeight != rightHeight, we can take the help of recursion and say to recursively find the number of nodes in the left subtree (say leftNodes) and in the right subtree(say rightNodes) and then return 1 + leftNodes + rightNodes.


*/








