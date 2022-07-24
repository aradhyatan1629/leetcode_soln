class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        int i=0,j=0,n=grid[0].size()-1;
        for(i=0;i<grid.size();i++)
        {
            for(j=0;j<=n;++j)
            {
                if(i==j or j==n-i)
                {
                    if(grid[i][j]==0)
                    {
                        return false;
                    }
                    else
                    {
                        continue;
                    }
                }
                else
                {
                    if(grid[i][j]!=0)
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};