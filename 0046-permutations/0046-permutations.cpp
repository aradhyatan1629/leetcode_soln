class Solution {
public:
    vector<vector<int>> ans;
    void solve(int ind,int n,vector<int> &v,vector<int> &nums,vector<int> &vis)
    {
        if(ind>=n)
        {
            if(v.size()==n)
                ans.push_back(v);
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                vis[i]=1;
                v.push_back(nums[i]);
                solve(ind+1,n,v,nums,vis);
                vis[i]=0;
                v.pop_back();
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<int> v,vis(n,0);
        solve(0,n,v,nums,vis);
        return ans;
    }
};

// tc - (n!)*n


