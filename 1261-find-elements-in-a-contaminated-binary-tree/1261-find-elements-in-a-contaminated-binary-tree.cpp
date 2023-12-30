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
class FindElements {
public:
    unordered_map<int,int> m;
    void solve(TreeNode *root)
    {
        if(root==NULL)
            return;
        if(root->left)
        {
            root->left->val = 2*root->val + 1;
            m[root->left->val]++;
        }
        if(root->right)
        {
            root->right->val = 2*root->val + 2;
            m[root->right->val]++;
        }
        solve(root->left);
        solve(root->right);
        
    }
    FindElements(TreeNode* root) {
        m[0]=1;
        root->val = 0;
        solve(root);
    }
    
    bool find(int target) {
        if(m[target]!=0)
            return true;
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */