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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        TreeNode *root;
        int n = descriptions.size();
        unordered_set<int> st;
        for(int i=0;i<n;i++)
            st.insert(descriptions[i][1]);
        for(int i=0;i<n;i++)
            if(st.find(descriptions[i][0]) == st.end())
            {
                root = new TreeNode(descriptions[i][0]);
                break;
            }
        
        unordered_map<int,pair<int,int>> m;  //{node,{lchild,rchild}}
        for(int i=0;i<n;i++)
        {
            if(descriptions[i][2])
                m[descriptions[i][0]].first = descriptions[i][1];
            else
                m[descriptions[i][0]].second = descriptions[i][1];
        }
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int sz = q.size();
            for(int i=0;i<sz;i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if(m[node->val].first != 0)
                {
                    TreeNode *t = new TreeNode(m[node->val].first);
                    node->left = t;
                    q.push(t);
                }
                if(m[node->val].second != 0)
                {
                    TreeNode *t = new TreeNode(m[node->val].second);
                    node->right = t;
                    q.push(t);
                }
            }
        }
        return root;
    }
};