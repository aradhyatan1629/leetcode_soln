class Solution {
public:
    int solve(int ind,int target,vector<vector<int>> &dp,vector<int> &coins)
    {
        if(ind==0)
        {
            if(target%coins[0]==0)
                return 1;
            return 0;
        }
        if(dp[ind][target]!=-1)
            return dp[ind][target];
        int notTake = solve(ind-1,target,dp,coins);
        int take = 0;
        if(coins[ind]<=target)
            take = solve(ind,target-coins[ind],dp,coins);
        dp[ind][target] = notTake + take;
        return dp[ind][target];
    }
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return solve(n-1,amount,dp,coins);
    }
};