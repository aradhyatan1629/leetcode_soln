class Solution {
public:
    int solve(int ind,int prev,int k,string &s,vector<vector<int>> &dp)
    {
        if(ind == 0)
        {
            if(abs(prev-s[ind])<=k)
                return 1;
            return 0;
        }
        if(dp[ind][prev]!=-1)
            return dp[ind][prev];
        int notPick = 0 + solve(ind-1,prev,k,s,dp);
        int pick = 0;
        if(prev==0 or abs(prev-s[ind])<=k)
            pick = 1 + solve(ind-1,s[ind],k,s,dp);
        dp[ind][prev] = max(notPick,pick);
        return dp[ind][prev];
    }
    
    int longestIdealString(string s, int k) {
        int n = s.size();
        if(n==1)
            return 1;
        vector<vector<int>> dp(n+1,vector<int>(200,-1));
        return solve(n-1,0,k,s,dp);
    }
};