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
    int minV(vector<int> &v,int target)
    {
        int low = 0, high = v.size()-1;
        int mini = INT_MIN;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(v[mid] == target)
            {
                return v[mid];
            }
            else if(v[mid] < target)
            {
                mini = max(mini,v[mid]);
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }
        if(mini == INT_MIN)
            return -1;
        return mini;
    } //1,2,4,6,9,13,14,15
    int maxV(vector<int> &v,int target)
    {
        int low = 0,high = v.size()-1;
        int maxi = INT_MAX;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(v[mid] == target)
            {
                return v[mid];
            }
            else if(v[mid] > target)
            {
                maxi = min(maxi,v[mid]);
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        if(maxi == INT_MAX)
            return -1;
        return maxi;
    }
    
    void inorder(TreeNode *root,vector<int> &v)
    {
        if(root==NULL)
            return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>> ans;
        if(root==NULL)
            return {};
        vector<int> v;
        inorder(root,v);
        
        for(int i=0;i<queries.size();i++)
        {
            int low = 0,high = v.size()-1;
            int target = queries[i];
            int mn = minV(v,target);
            int mx = maxV(v,target);
            ans.push_back({mn,mx});
        }
        return ans;
    }
};