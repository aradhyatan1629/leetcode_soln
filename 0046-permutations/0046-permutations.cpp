class Solution {
public:
    void solve(int ind,vector<int> &nums,vector<int> &v,vector<vector<int>> &ans,vector<int> &vis){
        if(ind >= nums.size()){
            if(v.size() == nums.size())
                ans.push_back(v);
            return;
        }
        
        for(int i=0;i<nums.size();i++){
            if(!vis[i]){
                vis[i] = 1;
                v.push_back(nums[i]);
                solve(ind+1,nums,v,ans,vis);
                vis[i] = 0;
                v.pop_back();
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v,vis(nums.size(),0);
        solve(0,nums,v,ans,vis);
        return ans;
    }
};