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
    
    int cnt=0;
    
    void preorder(TreeNode *root,map<int,int> &m)
    {
        if(root==NULL)
        {
            return;
        }
        m[root->val]++;
        auto it= m.end();
        it--;
        int x = it->first;
        // cout<<x<<endl;
        if(x<=root->val)
        {
            cnt++;
        }
        // cout<<cnt<<endl;
        // cout<<"hi"<<endl;
        preorder(root->left,m);   
        preorder(root->right,m);
        m[root->val]--;
        if(m[root->val]==0)
        {
            m.erase(root->val);
        }
    }
    int goodNodes(TreeNode* root) {
        map<int,int> m;
        preorder(root,m);
        return cnt;
    }
};












