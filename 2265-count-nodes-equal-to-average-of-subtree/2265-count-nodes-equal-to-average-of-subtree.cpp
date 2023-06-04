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
    
    //Postorder O(n) solution  pair - {sum,count}
    
    int ans=0;
    pair<int,int> solve(TreeNode *root)
    {
        if(root==NULL)
        {
            return {0,0};
        }
        auto left = solve(root->left);
        int left_sum = left.first;
        int left_cnt = left.second;
        
        auto right = solve(root->right);
        int right_sum = right.first;
        int right_cnt = right.second;
        
        int sum = root->val + left_sum + right_sum;
        int cnt = left_cnt + right_cnt + 1;
        
        if(sum/cnt==root->val)
        {
            ans++;
        }
        return {sum,cnt};
    }
    
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return ans;
    }
};