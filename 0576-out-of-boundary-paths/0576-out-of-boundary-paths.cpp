class Solution {
public:
    int mod = 1e9+7;
    int solve(int i,int j,int m,int n,int moves,vector<vector<vector<int>>> &dp)
    {
        if(i<0 || i>=m || j<0 || j>=n)
            return 1;
        if(moves <= 0)
            return 0;
        if(dp[i][j][moves] != -1)
            return dp[i][j][moves];
        int up = solve(i-1,j,m,n,moves-1,dp);
        int left = solve(i,j-1,m,n,moves-1,dp);
        int down = solve(i+1,j,m,n,moves-1,dp);
        int right = solve(i,j+1,m,n,moves-1,dp);
        dp[i][j][moves] = ((up + left)%mod + (down + right)%mod)%mod;
        return dp[i][j][moves];
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(maxMove+1,-1)));
        return solve(startRow,startColumn,m,n,maxMove,dp);
    }
};