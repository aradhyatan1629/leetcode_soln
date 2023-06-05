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
    
    vector<vector<int>> bfs(TreeNode *root)
    {
        map<int,map<int,multiset<int>>> m;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        
        while(!q.empty())
        {
            auto p = q.front();
            q.pop();
            
            TreeNode *node = p.first;
            int x_vertical = p.second.first;
            int y_level = p.second.second;
            
            m[x_vertical][y_level].insert(node->val);
            if(node->left)
            {
                q.push({node->left,{x_vertical-1,y_level+1}});
            }
            if(node->right)
            {
                q.push({node->right,{x_vertical+1,y_level+1}});
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
        return bfs(root);
    }
};