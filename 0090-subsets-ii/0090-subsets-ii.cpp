class Solution {
public:
    void solve(int ind,vector<int> &nums,vector<int> &v,vector<vector<int>> &ans){
        if(ind >= nums.size()){
            ans.push_back(v);
            return;
        }
        v.push_back(nums[ind]);
        solve(ind+1,nums,v,ans);
        v.pop_back();
        
        while(ind<nums.size()-1 && nums[ind]==nums[ind+1])
            ind++;
        solve(ind+1,nums,v,ans);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> v;
        solve(0,nums,v,ans);
        return ans;
    }
};