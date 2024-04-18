class Solution {
public:
    void dfs(int row,int col,vector<vector<int>> &vis,vector<vector<int>> &grid,int delRow[],int delCol[],int initialCol)
    {
        vis[row][col] = 1;
        int m = grid.size(),n=grid[0].size();
        for(int i=0;i<4;i++)
        {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if(nrow>=0 and nrow<m and ncol>=0 and ncol<n and grid[nrow][ncol]==initialCol && !vis[nrow][ncol])
                dfs(nrow,ncol,vis,grid,delRow,delCol,initialCol);
        }
    }
    
    bool check(int i,int j,int m,int n,vector<vector<int>> &vis)
    {
        if(i==m-1 || i==0 || j==n-1 || j==0)
            return true;
        if(vis[i-1][j]==1 && vis[i+1][j] && vis[i][j-1]==1 && vis[i][j+1]==1)
            return false;
        return true;
    }
    
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int m = grid.size(),n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,+1,0,-1};
        
        int initialCol = grid[row][col];
        dfs(row,col,vis,grid,delRow,delCol,initialCol);

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == initialCol && vis[i][j]==1 && check(i,j,m,n,vis))
                    grid[i][j] = color;
            }
        }
        return grid;
    }
};