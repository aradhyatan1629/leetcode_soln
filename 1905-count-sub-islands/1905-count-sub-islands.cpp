class Solution {
public:
    void dfs(int row,int col,vector<vector<int>> &vis,vector<vector<int>> &grid1,vector<vector<int>> &grid2,int delRow[],int delCol[],bool &flag)
    {
        vis[row][col] = 1;
        if(grid1[row][col]!=1)
            flag = false;
        
        int m = grid2.size(),n=grid2[0].size();
        for(int i=0;i<4;i++)
        {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol] && grid2[nrow][ncol]==1)
            {
                dfs(nrow,ncol,vis,grid1,grid2,delRow,delCol,flag);
            }
        }
        if(!flag)
            grid2[row][col] = -1;
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size(),n=grid1[0].size();
        
        vector<vector<int>> vis(m,vector<int>(n,0));
        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,+1,0,-1};
        
        int ans = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid2[i][j]==1 && !vis[i][j])
                {
                    bool flag = true;
                    dfs(i,j,vis,grid1,grid2,delRow,delCol,flag);
                    if(flag)
                    {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};