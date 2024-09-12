class Solution {
public:
    void solve(int start,vector<int> &nums,vector<int> &v,vector<vector<int>> &ans){
        ans.push_back(v);
        for(int i=start;i<nums.size();i++){
            if(i!=start && nums[i] == nums[i-1])
                continue;
            v.push_back(nums[i]);
            solve(i+1,nums,v,ans);
            v.pop_back();
        }
        
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> v;
        solve(0,nums,v,ans);
        return ans;
    }
};