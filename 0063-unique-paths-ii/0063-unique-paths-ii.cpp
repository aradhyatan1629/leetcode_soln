class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size(),n=grid[0].size();
        if(grid[0][0]==1 or grid[m-1][n-1]==1)
            return 0;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 and j==0)
                {
                    dp[i][j] = 1;continue;
                }
                int up=0,left=0;
                if(i>0 and grid[i-1][j]!=1)
                    up = dp[i-1][j];
                if(j>0 and grid[i][j-1]!=1)
                    left = dp[i][j-1];
                dp[i][j] = up+left;
            }
        }
        return dp[m-1][n-1];
    }
};