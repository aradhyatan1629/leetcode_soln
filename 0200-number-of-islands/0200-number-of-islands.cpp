class Solution {
public:
    void dfs(int row,int col,vector<vector<char>> &grid,vector<vector<int>> &vis,int delRow[],int delCol[])
    {
        vis[row][col] = 1;
        int m=grid.size();
        int n=grid[0].size();
        
        for(int i=0;i<4;i++)
        {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if(nrow>=0 and nrow<m and ncol>=0 and ncol<n and grid[nrow][ncol]=='1' and vis[nrow][ncol]==0)
            {
                dfs(nrow,ncol,grid,vis,delRow,delCol);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int cnt = 0;
        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,+1,0,-1};
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1' and vis[i][j]==0)
                {
                    cnt++;
                    dfs(i,j,grid,vis,delRow,delCol);
                }
            }
        }
        return cnt;
    }
};