class Solution {
public:
    
    int sum(vector<vector<int>> &grid,int i,int j)
    {
        return grid[i-1][j-1] + grid[i-1][j] + grid[i-1][j+1] + grid[i][j] + grid[i+1][j-1] + grid[i+1][j] + grid[i+1][j+1];
    }
    
    int maxSum(vector<vector<int>>& grid) {
        int mx=0;
        int m=grid.size(),n=grid[0].size();
        
        for(int i=1;i<m-1;i++)
        {
            for(int j=1;j<n-1;j++)
            {
                mx = max(mx,sum(grid,i,j));
            }
        }
        return mx;
    }
};
