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
        int n = descriptions.size();
        unordered_map<int,TreeNode*> m;     // node_val,node_address
        
        for(int i=0;i<n;i++)
        {
            int p=descriptions[i][0],c=descriptions[i][1],isLeft=descriptions[i][2];
            if(m[p]==NULL or m[c]==NULL)
            {
                if(m[p]==NULL)
                    m[p] = new TreeNode(p);
                if(m[c]==NULL)
                    m[c] = new TreeNode(c);
                if(isLeft==1)
                    m[p]->left = m[c];
                if(isLeft==0)
                    m[p]->right = m[c];
            }
            else      //if both parent and child have already been created
            {
                if(isLeft==1)
                    m[p]->left = m[c];
                if(isLeft==0)
                    m[p]->right = m[c];
            }
        }
        // for(auto x:m)
        // {
        //     cout<<x.first<<" ";
        //     if(m[x.first]->left!=NULL)
        //         cout<<"lchild "<<m[x.first]->left->val<<" ";
        //     if(m[x.first]->right!=NULL)
        //         cout<<"rchild "<<m[x.first]->right->val<<" ";
        //     cout<<endl;
        // }
        
         unordered_set<int> st;
         for(int i=0;i<n;i++)
             st.insert(descriptions[i][1]);
         for(int i=0;i<n;i++)
             if(st.find(descriptions[i][0]) == st.end())
                 return m[descriptions[i][0]];
        
        return NULL;
        
    }
};