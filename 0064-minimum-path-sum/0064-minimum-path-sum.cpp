class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 and j==0)
                {
                    dp[i][j] = grid[i][j];
                    continue;
                }
                int up = grid[i][j];
                if(i>0)
                    up += dp[i-1][j];
                else
                    up = 1e9;
                int left = grid[i][j];
                if(j>0)
                    left += dp[i][j-1];
                else
                    left = 1e9;
                dp[i][j] = min(up,left);
            }
        }
        return dp[m-1][n-1];
    }
}; 

// Tabulation
// t.c. - O(m+n)
// s.c. - O(m*n) extra dp array