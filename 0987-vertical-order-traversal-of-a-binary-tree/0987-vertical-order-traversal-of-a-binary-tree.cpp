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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> m;    //{vertical,{level,{nodes}}}
        queue<pair<TreeNode*,pair<int,int>>> q;     // {node,{vertical,level}}
        
        q.push({root,{0,0}});
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            TreeNode *node = it.first;
            int vertical = it.second.first;
            int level = it.second.second;
            
            m[vertical][level].insert(node->val);
            
            if(node->left)
                q.push({node->left,{vertical-1,level+1}});
            if(node->right)
                q.push({node->right,{vertical+1,level+1}});
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
};



/*
vertical - is like points on x axis
levels - is like points on y axis
*/