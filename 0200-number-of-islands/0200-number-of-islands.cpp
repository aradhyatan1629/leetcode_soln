class Solution {
public:
    void dfs(int row,int col,vector<vector<int>> &vis,vector<vector<char>> &grid,int delRow[],int delCol[])
    {
        vis[row][col] = 1;
        int m = grid.size(),n=grid[0].size();
        for(int i=0;i<4;i++)
        {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n and !vis[nrow][ncol] && grid[nrow][ncol]=='1')
            {
                dfs(nrow,ncol,vis,grid,delRow,delCol);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(),n=grid[0].size();
        int cnt = 0;
        vector<vector<int>> vis(m,vector<int>(n,0));
        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,+1,0,-1};
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == '1' && !vis[i][j])
                {
                    cnt++;
                    dfs(i,j,vis,grid,delRow,delCol);
                }
            }
        }
        return cnt;
    }
};