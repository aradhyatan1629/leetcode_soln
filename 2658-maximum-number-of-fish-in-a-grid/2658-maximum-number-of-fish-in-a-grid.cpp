class Solution {
public:
    
    void dfs(int i,int j,vector<vector<int>> &vis,vector<vector<int>> &grid,int delRow[],int delCol[],int &mx,int &cnt)
    {
        vis[i][j] = 1;
        int row=i;
        int col=j;
        int m = grid.size(),n=grid[0].size();
        
        for(int i=0;i<4;i++)
        {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if(nrow>=0 and nrow<m and ncol>=0 and ncol<n and !vis[nrow][ncol] and grid[nrow][ncol]>0)
            {
                cnt+=grid[nrow][ncol];
                dfs(nrow,ncol,vis,grid,delRow,delCol,mx,cnt);
            }
        }
    }
    
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,+1,0,-1};
        int mx = 0;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]>0 and !vis[i][j])
                {
                    int cnt=grid[i][j];
                    dfs(i,j,vis,grid,delRow,delCol,mx,cnt);
                    mx = max(mx,cnt);
                }
            }
        }
        return mx;
    }
};