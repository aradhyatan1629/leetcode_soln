class Solution {
public:
    int solve(int i,int j,int m,int n,vector<vector<int>> &dp,vector<vector<int>> &matrix)
    {
        if(j<0 or j>=n)
            return 1e9;
        if(i==0)
            return matrix[0][j];
        if(dp[i][j]!=1e9)
            return dp[i][j];
        int up = matrix[i][j] + solve(i-1,j,m,n,dp,matrix);
        int leftDiagonal = matrix[i][j] + solve(i-1,j-1,m,n,dp,matrix);
        int rightDiagonal = matrix[i][j] + solve(i-1,j+1,m,n,dp,matrix);
        dp[i][j] = min(up,min(leftDiagonal,rightDiagonal));
        return dp[i][j];
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int mn = INT_MAX;
        int m = matrix.size(),n = matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,1e9));
        for(int j=0;j<n;j++)
        {
            mn = min(mn,solve(m-1,j,m,n,dp,matrix));
        }
        return mn;
    }
};



