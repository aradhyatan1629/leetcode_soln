class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int i=0,j=0;
        int temp = grid[m-1][n-1];
        if(n==1)
        {
            while(k--)
            {
                for(int i=m-1;i>0;i--)
                {
                    grid[i][0] = grid[i-1][0];
                }
                grid[0][0] = temp;
                temp = grid[m-1][0];
            }
            return grid;
        }
        while(k--)
        {
            for(i=m-1;i>=0;i--)
            {
                for(j=n-2;j>=0;j--)
                {
                    grid[i][j+1] = grid[i][j];
                    if(i==0 and j==0)
                    {
                        grid[i][j] = temp;
                        temp=grid[m-1][n-1];
                    }
                    else if(j==0 and i>0)
                    {
                        grid[i][0]=grid[i-1][n-1];
                    }
                }
            }
        }
        return grid;
    }
};