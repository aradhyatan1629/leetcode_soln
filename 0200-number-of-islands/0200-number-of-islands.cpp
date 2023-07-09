class Solution {
public:
    void bfs(int row,int col,vector<vector<char>> &grid,vector<vector<int>> &vis,int delRow[],int delCol[])
    {
        vis[row][col] = 1;
        queue<pair<int,int>> q;
        q.push({row,col});
        int m = grid.size();
        int n = grid[0].size();
        
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
                if(nrow>=0 and nrow<m and ncol>=0 and ncol<n and vis[nrow][ncol]==0 and grid[nrow][ncol]=='1')
                {
                    q.push({nrow,ncol});
                    vis[nrow][ncol] = 1;
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int cnt=0;
        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,+1,0,-1};
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1' and vis[i][j]==0)
                {
                    cnt++;
                    bfs(i,j,grid,vis,delRow,delCol);
                }
            }
        }
        return cnt;
    }
};