class Solution {
public:
    void solve(int ind,vector<int> &nums,vector<int> &v,vector<vector<int>> &ans,int k){
        if(ind >= nums.size())
        {
            if(k == 0)ans.push_back(v);
            return;
        }
        if(k == 0)
        {
            ans.push_back(v);
            return;
        }
        
        if(nums[ind] <= k){
            v.push_back(nums[ind]);
            solve(ind,nums,v,ans,k-nums[ind]);
            v.pop_back();
        }
        while(ind<nums.size()-1 && nums[ind] == nums[ind+1])
            ind++;
        solve(ind+1,nums,v,ans,k);
    }
    
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        
        solve(0,nums,v,ans,target);
        return ans;
    }
};