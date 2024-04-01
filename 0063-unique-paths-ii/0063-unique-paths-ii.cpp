class Solution {
public:
    int solve(int i,int j,vector<vector<int>> &dp,vector<vector<int>> &grid)
    {
        if(i==0 and j==0)
            return 1;
        if((i<0 or j<0) or grid[i][j]==1)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        dp[i][j] = solve(i-1,j,dp,grid) + solve(i,j-1,dp,grid);
        return dp[i][j];
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        if(grid[0][0]==1)
            return 0;
        return solve(m-1,n-1,dp,grid);
    }
};