class Solution {
    public int solve(int i, int j, int m, int n, int lastVal, int[][] grid, int[][] dp) {
        if (i < 0 || i >= m || j >= n || grid[i][j] <= lastVal) {
            return -1;
        }
        
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        
        int upL = 1 + solve(i - 1, j + 1, m, n, grid[i][j], grid, dp);
        int right = 1 + solve(i, j + 1, m, n, grid[i][j], grid, dp);
        int downR = 1 + solve(i + 1, j + 1, m, n, grid[i][j], grid, dp);
        
        return dp[i][j] = Math.max(upL, Math.max(right, downR));
    }
    
    public int maxMoves(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;        
        int ans = 0;
        
        int[][] dp = new int[m][n];
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = -1;
            }
        }
        
        for (int i = 0; i < m; i++) {
            ans = Math.max(ans, solve(i, 0, m, n, -1, grid, dp));
        }
        
        return ans;
    }
}
