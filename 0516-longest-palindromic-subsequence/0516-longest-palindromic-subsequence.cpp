class Solution {
public:
    int solve(int ind1,int ind2,string &s,vector<vector<int>> &dp)
    {
        if(ind1==ind2 || ind1>ind2)
            return ind1==ind2;
        if(dp[ind1][ind2]!=-1)
            return dp[ind1][ind2];
        if(s[ind1] == s[ind2])
            return dp[ind1][ind2] = 2 + solve(ind1+1,ind2-1,s,dp);
        return dp[ind1][ind2] = 0 + max(solve(ind1+1,ind2,s,dp),solve(ind1,ind2-1,s,dp));
    }
    
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(0,n-1,s,dp);
    }
};