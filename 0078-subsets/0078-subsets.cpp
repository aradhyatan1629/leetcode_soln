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
        solve(ind+1,n,nums,v);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<int> v;
        solve(0,n,nums,v);
        return ans;
    }
};