class Solution {
public:
    vector<vector<int>> ans;
    void solve(int ind,int n,vector<int> &nums,vector<int> &v)
    {
        if(ind>=n)
        {
            ans.push_back(v);
            return;
        }
        v.push_back(nums[ind]);
        solve(ind+1,n,nums,v);
        v.pop_back();
        while(ind<n-1 and nums[ind]==nums[ind+1])
            ind++;
        solve(ind+1,n,nums,v);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> v;
        solve(0,n,nums,v);
        return ans;
    }
};

/*
tc - nlogn + (2^n)*(k)
k is the average length of each subset
*/


