class Solution {
public:
    int solve(int i, int j, int m, int n, vector<vector<int>> &grid, int lastVal, vector<vector<int>> &dp) {
        if (i < 0 || i >= m || j >= n || grid[i][j] <= lastVal) {
            return -1;
        }
        
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        
        int upL = 1 + solve(i - 1, j + 1, m, n, grid, grid[i][j], dp);
        int right = 1 + solve(i, j + 1, m, n, grid, grid[i][j], dp);
        int downR = 1 + solve(i + 1, j + 1, m, n, grid, grid[i][j], dp);
        
        return dp[i][j] = max(upL, max(right, downR));
    }
    
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        for (int i = 0; i < m; i++) {
            ans = max(ans, solve(i, 0, m, n, grid, 0, dp));
        }
        
        return ans;
    }
};
