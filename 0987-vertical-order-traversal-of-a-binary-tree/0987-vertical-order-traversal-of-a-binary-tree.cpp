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
    
    vector<vector<int>> solve(TreeNode *root)
    {
        queue<pair<TreeNode*,pair<int,int>>> q;
        map<int,map<int,multiset<int>>> m;
        q.push({root,{0,0}});
        
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            
            TreeNode *node = it.first;
            int x = it.second.first;
            int y = it.second.second;
            
            m[x][y].insert(node->val);
            
            if(node->left)
            {
                q.push({node->left,{x-1,y+1}});
            }
            if(node->right)
            {
                q.push({node->right,{x+1,y+1}});
            }
        }
        
        vector<vector<int>> ans;
        for(auto x:m)
        {
            vector<int> v;
            for(auto y:x.second)
            {
                v.insert(v.end(),y.second.begin(),y.second.end());
            }
            ans.push_back(v);
        }
        return ans;
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        return solve(root);
    }
};