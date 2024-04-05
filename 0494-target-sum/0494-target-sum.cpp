class Solution {
public:
    int solve(int ind,int target,vector<vector<int>> &dp,vector<int> &nums)
    {
        if(ind==0)
        {
            if(target==0 and nums[0]==0)
                return 2;
            if(target==0 or target==nums[0])
                return 1;
            return 0;
        }
        if(dp[ind][target]!=-1)
            return dp[ind][target];
        int notTake = solve(ind-1,target,dp,nums);
        int take = 0;
        if(nums[ind]<=target)
            take = solve(ind-1,target-nums[ind],dp,nums);
        dp[ind][target] = notTake + take;
        return dp[ind][target];
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = 0;
        int n = nums.size();
        for(int i=0;i<nums.size();i++)
            totalSum+=nums[i];
        if(totalSum-target<0)
            return 0;
        if((totalSum-target)%2!=0)
            return 0;
        
        int s2 = (totalSum-target)/2;
        vector<vector<int>> dp(n,vector<int>(s2+1,-1));
        return solve(n-1,s2,dp,nums);
    }
};