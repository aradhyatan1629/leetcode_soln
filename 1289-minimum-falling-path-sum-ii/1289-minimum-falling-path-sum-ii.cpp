class Solution {
public:
    int solve(int i,int j,int n,vector<vector<int>> &grid,vector<vector<int>> &dp)
    {
        if(i==n-1)
            return grid[i][j];
        if(dp[i][j] != -1)
            return dp[i][j];
        int mn = 1e9;
        for(int k=0;k<n;k++)
        {
            if(k!=j)
            {
                int sum = grid[i][j] + solve(i+1,k,n,grid,dp);
                mn = min(mn,sum);
            }
        }
        return dp[i][j] = mn;
    }
    
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int mn = INT_MAX;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int j=0;j<n;j++)
        {
            mn = min(mn,solve(0,j,n,grid,dp));
        }
        return mn;
    }
};