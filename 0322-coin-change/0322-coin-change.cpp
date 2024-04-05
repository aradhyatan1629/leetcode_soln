class Solution {
public:
    int solve(int ind,int target,vector<vector<int>> &dp,vector<int> &coins)
    {
        if(ind==0)
        {
            if(target%coins[0]==0)
                return target/coins[0];
            return 1e9;
        }
        if(dp[ind][target]!=-1)
            return dp[ind][target];
        int notTake = 0 + solve(ind-1,target,dp,coins);
        int take = 1e9;
        if(coins[ind]<=target)
            take = 1 + solve(ind,target-coins[ind],dp,coins);
        dp[ind][target] = min(notTake,take);
        return dp[ind][target];
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
    
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans = solve(n-1,amount,dp,coins);
        if(ans == 1e9)
            return -1;
        return ans;
    }
};