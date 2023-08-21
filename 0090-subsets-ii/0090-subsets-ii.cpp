class Solution {
public:
    
    vector<vector<int>> ans;
    void f(int ind,vector<int> &nums,vector<int> &subs,int n)
    {
        if(ind>=n)
        {
            ans.push_back(subs);
            return;
        }
        subs.push_back(nums[ind]);
        f(ind+1,nums,subs,n);
        subs.pop_back();
        while(ind+1<n and nums[ind]==nums[ind+1])
        {
            ind++;
        }
        f(ind+1,nums,subs,n);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> subs;
        sort(nums.begin(),nums.end());
        f(0,nums,subs,nums.size());
        return ans;
    }
};