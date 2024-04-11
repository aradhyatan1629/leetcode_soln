class Solution {
public:
    int solve(int i,int j,int n,vector<vector<int>> &dp,vector<vector<int>> &matrix)
    {
        if(j<0 || j>=n)
            return 1e9;
        if(i==n-1)
            return matrix[i][j];
        if(dp[i][j]!=1e9)
            return dp[i][j];
        int down = matrix[i][j] + solve(i+1,j,n,dp,matrix);
        int diagonalLeft = matrix[i][j] + solve(i+1,j-1,n,dp,matrix);
        int diagonalRight = matrix[i][j] + solve(i+1,j+1,n,dp,matrix);
        dp[i][j] = min(down,min(diagonalLeft,diagonalRight));
        return dp[i][j];
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int mn = INT_MAX;
        vector<vector<int>> dp(n,vector<int>(n,1e9));
        for(int j=0;j<n;j++)
        {
            int ans = solve(0,j,n,dp,matrix);
            mn = min(mn,ans);
        }
        return mn;
    }
};