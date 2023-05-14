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
    
    int maxDepth(TreeNode *root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int leftH = maxDepth(root->left);
        int rightH = maxDepth(root->right);
        return 1 + max(leftH,rightH);
            
    }
    
    int h=0;
    int sum = 0;
    
    void inorder(TreeNode *root,int maxD)
    {
        if(root==NULL)
        {
            return;
        }
        h++;
        if(h==maxD)
        {
            sum+=root->val;
        }
        inorder(root->left,maxD);
        inorder(root->right,maxD);
        h--;
    }
    
    int deepestLeavesSum(TreeNode* root) {
        int maxD = maxDepth(root);
        inorder(root,maxD);
        return sum;
    }
};