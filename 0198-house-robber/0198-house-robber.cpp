class Solution {
public:
    int solve(int ind,vector<int> &dp,vector<int> &nums)
    {
        if(ind==0)
            return nums[0];
        if(ind<0)
            return 0;
        if(dp[ind]!=-1)
            return dp[ind];
        int notTake = 0 + solve(ind-1,dp,nums);
        int take = nums[ind] + solve(ind-2,dp,nums);
        dp[ind] = max(take,notTake);
        return dp[ind];
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1);
        return solve(n-1,dp,nums);
    }
};