class Solution {
public:
    int solve(int ind,vector<int> &dp)
    {
        if(ind==0 || ind==1)
            return 1;
        if(dp[ind]!=-1)
            return dp[ind];
        int stepOne = solve(ind-1,dp);
        int stepTwo = 0;
        if(ind>1)
            stepTwo = solve(ind-2,dp);
        return dp[ind] = stepOne + stepTwo;
    }
    
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};