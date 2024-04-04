class Solution {
public:
    bool solve(int ind,int target,vector<vector<int>> &dp,vector<int> &nums)
    {
        if(target==0)
            return true;
        if(ind==0)
            return nums[ind]==target;
        if(dp[ind][target]!=-1)
            return dp[ind][target];
        bool notTake = solve(ind-1,target,dp,nums);
        bool take = false;
        if(nums[ind]<=target)
            take = solve(ind-1,target-nums[ind],dp,nums);
        dp[ind][target] = notTake || take;
        return dp[ind][target];
    }
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size(),s=0;
        for(int i=0;i<nums.size();i++)
            s+=nums[i];
        
        if(s%2!=0)
            return false;
        int target = s/2;
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return solve(n-1,target,dp,nums);
    }
};