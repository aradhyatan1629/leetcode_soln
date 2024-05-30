class Solution {
public:
    void solve(int ind,int n,vector<int> &v,vector<int> &nums,vector<vector<int>> &ans)
    {
        if(ind>=n)
        {
            ans.push_back(v);
            return;
        }
        v.push_back(nums[ind]);
        solve(ind+1,n,v,nums,ans);
        v.pop_back();
        solve(ind+1,n,v,nums,ans);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        int n = nums.size();
        solve(0,n,v,nums,ans);
        return ans;
    }
};