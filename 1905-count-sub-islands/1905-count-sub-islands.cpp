class Solution {
public:
    
    bool dfs(int row,int col,vector<vector<int>> &vis,vector<vector<int>> &grid1,vector<vector<int>> &grid2,int delRow[],int delCol[],bool &t)
    {
        vis[row][col] = 1;
        if(grid1[row][col]!=1)
        {
            t=false;
        }
        int m = grid2.size();
        int n = grid2[0].size();
        for(int i=0;i<4;i++)
        {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if(nrow>=0 and nrow<m and ncol>=0 and ncol<n and !vis[nrow][ncol] and grid2[nrow][ncol]==1)
            {
                if (!dfs(nrow, ncol, vis, grid1, grid2, delRow, delCol,t))
                {
                    t = false;
                }
            }
        }
        return t;
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size();
        int n = grid1[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        
        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,+1,0,-1};
        
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!vis[i][j] and grid2[i][j]==1)
                {
                    bool t = true;
                    dfs(i,j,vis,grid1,grid2,delRow,delCol,t);
                    if(t)
                    {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};