class Solution {
public:
    int solve(int ind1,int ind2,string &s1,string &s2,vector<vector<int>> &dp)
    {
        if(ind1<0 || ind2<0)
            return 0;
        if(dp[ind1][ind2] != -1)
            return dp[ind1][ind2];
        if(s1[ind1] == s2[ind2])
            return dp[ind1][ind2] = 1 + solve(ind1-1,ind2-1,s1,s2,dp);
        return dp[ind1][ind2] = 0 + max(solve(ind1-1,ind2,s1,s2,dp),solve(ind1,ind2-1,s1,s2,dp));
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(),n=text2.size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,text1,text2,dp);
    }
};