class Solution {
public:
    
    void dfs(int row,int col,vector<vector<int>> &vis,vector<vector<int>> &grid,int delRow[],int delCol[])
    {
        vis[row][col] = 1;
        int m=grid.size(),n=grid[0].size();
        for(int i=0;i<4;i++)
        {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if(nrow>=0 and nrow<m and ncol>=0 and ncol<n and grid[nrow][ncol]==0 and !vis[nrow][ncol])
            {
                dfs(nrow,ncol,vis,grid,delRow,delCol);
            }
        }
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis = grid;
        
        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,+1,0,-1};
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if((i==0 or i==m-1 or j==0 or j==n-1) and grid[i][j]==0)
                {
                    dfs(i,j,vis,grid,delRow,delCol);
                }
            }
        }
        
        int cnt=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!vis[i][j] and grid[i][j]==0)
                {
                    cnt++;
                    dfs(i,j,vis,grid,delRow,delCol);
                }
            }
        }
        return cnt;
    }
};