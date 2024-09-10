class Solution {
private:
    vector<vector<int>> ans;
    
public:
    void solve(int ind,vector<int> &nums,vector<int> &v,int k){
        if(ind>=nums.size()){
            if(k==0)
                ans.push_back(v);
            return;
        }
        
        if(nums[ind] <= k){
            v.push_back(nums[ind]);
            solve(ind+1,nums,v,k-nums[ind]);
            v.pop_back();
        }
        while(ind<nums.size()-1 && nums[ind]==nums[ind+1])
            ind++;
        solve(ind+1,nums,v,k);
    }
    
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int> v;
        solve(0,nums,v,target);
        return ans;
    }
};

// 1,1,2,5,6,7,10