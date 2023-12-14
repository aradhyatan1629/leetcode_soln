class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size(),n=grid[0].size();
        vector<vector<int>> ans(m,vector<int>(n,0));
        
        vector<int> row(m,0),col(n,0);
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    row[i]++;
                    col[j]++;
                }
            }
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int row1 = row[i],col1 = col[j];
                int row0 = n-row[i],col0 = m-col[j];
                ans[i][j] = (row1 + col1 - row0 - col0);
            }
        }
        return ans;
    }
};