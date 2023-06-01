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
    
    int sum=0,n=0;
    void dfs(TreeNode *root)
    {
        if(root==NULL)
        {
            return;
        }
        n = (n*10)+root->val;
        dfs(root->left);
        dfs(root->right);
        if(root->left==NULL and root->right==NULL)
        {
            sum+=n;
        }
        n/=10;
        // cout<<sum<<" "<<n<<endl;
    }
    
    int sumNumbers(TreeNode* root) {
        dfs(root);
        return sum;
    }
};