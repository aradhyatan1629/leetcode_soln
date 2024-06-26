class Solution {
public:
    int solve(string &text1,string &text2,int ind1,int ind2,vector<vector<int>> &dp)
    {
        if(ind1<0 || ind2<0)
            return 0;
        if(dp[ind1][ind2]!=-1)
            return dp[ind1][ind2];
        if(text1[ind1] == text2[ind2])
            return 1+solve(text1,text2,ind1-1,ind2-1,dp);
        return dp[ind1][ind2] = 0 + max(solve(text1,text2,ind1-1,ind2,dp),solve(text1,text2,ind1,ind2-1,dp));
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(text1,text2,m-1,n-1,dp);
    }
};