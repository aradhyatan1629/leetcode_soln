class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size(),n=grid[0].size();
        vector<vector<int>> ans(m,vector<int>(n,0));
        
        vector<int> row0(m,0),row1(m,0),col0(n,0),col1(n,0);
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0)
                {
                    row0[i]++;
                    col0[j]++;
                }
                else
                {
                    row1[i]++;
                    col1[j]++;
                }
            }
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans[i][j] = (row1[i]+col1[j] - row0[i] - col0[j]);
            }
        }
        return ans;
    }
};