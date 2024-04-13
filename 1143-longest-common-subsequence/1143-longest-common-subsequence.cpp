class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int m = s1.size(),n=s2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        
        for(int i=0;i<=m;i++)
            dp[i][0] = 0;
        for(int i=0;i<=n;i++)
            dp[0][i] = 0;
        
        for(int ind1=1;ind1<=m;ind1++)
        {
            for(int ind2=1;ind2<=n;ind2++)
            {
                if(s1[ind1-1] == s2[ind2-1])
                    dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
                else
                    dp[ind1][ind2] = 0 + max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
            }
        }
        return dp[m][n];
    }
};

// Tabulation with shifting the indices by 1 