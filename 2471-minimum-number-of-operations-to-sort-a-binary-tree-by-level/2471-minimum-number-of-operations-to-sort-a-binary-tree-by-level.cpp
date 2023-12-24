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
    int solve(vector<int> &v)
    {
        int cnt=0;
        vector<int> temp(v.begin(),v.end());
        sort(temp.begin(),temp.end());
        unordered_map<int,int> m;
        for(int i=0;i<v.size();i++)
            m[v[i]]=i;
        
        for(int i=0;i<v.size();i++)
        {
            if(v[i] != temp[i])
            {
                swap(v[i],v[m[temp[i]]]);
                m[v[m[temp[i]]]] = m[temp[i]];
                cnt++;
            }
        }
        return cnt;
    }
    int minimumOperations(TreeNode* root) {
        if(root==NULL)
            return 0;
        
        queue<TreeNode*> q;
        q.push(root);
        int ans=0;
        
        while(!q.empty())
        {
            int sz = q.size();
            vector<int> v;
            for(int i=0;i<sz;i++)
            {
                TreeNode *node = q.front();
                q.pop();
                v.push_back(node->val);
                if(node->left)
                {
                    q.push(node->left);
                }
                if(node->right)
                {
                    q.push(node->right);
                }
            }
            ans += solve(v);
            // cout<<ans<<endl;
        }
        return ans;
    }
};