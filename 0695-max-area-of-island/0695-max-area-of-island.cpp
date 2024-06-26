class Solution {
public:
    void bfs(int i,int j,vector<vector<int>> &vis,vector<vector<int>> &grid,int delRow[],int delCol[],int &cnt)
    {
        vis[i][j]=1;
        queue<pair<int,int>> q;
        q.push({i,j});
        int m = grid.size(),n=grid[0].size();
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
                if(nrow>=0 and nrow<m and ncol>=0 and ncol<n and grid[nrow][ncol]==1 and !vis[nrow][ncol])
                {
                    cnt++;
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        
        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,+1,0,-1};
        
        int mx=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1 and !vis[i][j])
                {
                    int cnt=1;
                    bfs(i,j,vis,grid,delRow,delCol,cnt);
                    mx = max(mx,cnt);
                }
            }
        }
        return mx;
    }
};