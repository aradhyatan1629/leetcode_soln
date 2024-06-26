class Solution {
public:
    int solve(int i,int j,int m,vector<vector<int>> &dp,vector<vector<int>> &triangle)
    {
        if(i==m-1)
            return triangle[i][j];
        if(dp[i][j]!=1e9)
            return dp[i][j];
        int down = triangle[i][j] + solve(i+1,j,m,dp,triangle);
        int diagonal = triangle[i][j] + solve(i+1,j+1,m,dp,triangle);
        dp[i][j] = min(down,diagonal);
        return dp[i][j];
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> dp(m,vector<int>(m,1e9));
        return solve(0,0,m,dp,triangle);
    }
};