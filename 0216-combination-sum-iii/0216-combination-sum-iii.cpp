class Solution {
private:
    vector<vector<int>> ans;
public:
    void solve(int ind,vector<int> &nums,vector<int> &v,int k,int target,int sz){
        
        if(ind >= nums.size()){
            if(target == 0 && v.size() == sz){
                ans.push_back(v);
            }
            return;
        }
        
        if(nums[ind] <= target && k>0){
            v.push_back(nums[ind]);
            solve(ind+1,nums,v,k-1,target-nums[ind],sz);
            v.pop_back();
        }
        solve(ind+1,nums,v,k,target,sz);
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums = {1,2,3,4,5,6,7,8,9};
        vector<int> v;
        solve(0,nums,v,k,n,k);
        return ans;
    }
};

// 1,2,3,4,5,6,7,8,9