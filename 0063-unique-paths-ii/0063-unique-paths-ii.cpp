class Solution {
public:
    int solve(int i,int j,vector<vector<int>> &dp,vector<vector<int>> &grid)
    {
        if(i==0 && j==0)
            return 1;
        if((i<0 || j<0) or grid[i][j]==1)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int up = solve(i-1,j,dp,grid);
        int left = solve(i,j-1,dp,grid);
        dp[i][j] = up+left;
        return dp[i][j];
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size(),n=grid[0].size();
        if(grid[0][0]==1)
            return 0;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,dp,grid);
    }
};