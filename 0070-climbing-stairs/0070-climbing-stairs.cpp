class Solution {
public:
    //Memoization O(n)
    
    int count(int n,vector<int> &dp)
    {
        if(n==0 or n==1)
        {
            return 1;
        }
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        dp[n] = count(n-1,dp) + count(n-2,dp);
        return dp[n];
    }
    
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return count(n,dp);
    }
};