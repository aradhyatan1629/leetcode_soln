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
    
    string ans;
    
    string findSmaller(string s1,string s2)
    {
        /*int i=0,j=0;
        while(i<s1.size() and j<s2.size())
        {
            if(s1[i]<s2[j])
            {
                return s1;
            }
            else if(s2[j]<s1[i])
            {
                return s2;
            }
            i++,j++;
        }*/
        if(s1<s2)
        {
            return s1;
        }
        if(s2<s1)
        {
            return s2;
        }
        return s1;
    }
    
    void dfs(TreeNode *root,string t)
    {
        if(root==NULL)
        {
            return;
        }
        t+=(char(root->val)+97);
        dfs(root->left,t);
        dfs(root->right,t);
        if(root->left==NULL and root->right==NULL)
        {
            reverse(t.begin(),t.end());
            if(ans.size()==0)
            {
                ans = t;
            }
            else
            {
                ans = findSmaller(ans,t);
            }
        }
    }
    
    string smallestFromLeaf(TreeNode* root) {
        dfs(root,"");
        return ans;
    }
};

/*
dba eda 
acd afg
efsd eda
*/