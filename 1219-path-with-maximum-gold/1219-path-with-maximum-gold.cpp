class Solution {
public:
    int solve(int i,int j,int m,int n,vector<vector<int>> &grid,vector<vector<int>> &vis)
    {
        if(i<0 || i>=m || j<0 || j>=n)
            return 0;
        if(grid[i][j]==0)
            return 0;
        int up=0,left=0,down=0,right=0;
        if(!vis[i][j])
        {
            vis[i][j] = 1;
            up = grid[i][j] + solve(i-1,j,m,n,grid,vis);
            vis[i][j] = 0;
        }
         if(!vis[i][j])
        {
            vis[i][j] = 1;
            left = grid[i][j] + solve(i,j-1,m,n,grid,vis);
            vis[i][j] = 0;
        }
         if(!vis[i][j])
        {
            vis[i][j] = 1;
            down = grid[i][j] + solve(i+1,j,m,n,grid,vis);
            vis[i][j] = 0;
        }
         if(!vis[i][j])
        {
            vis[i][j] = 1;
            right = grid[i][j] + solve(i,j+1,m,n,grid,vis);
            vis[i][j] = 0;
        }
        int a = max(up,left);
        int b = max(down,right);
        return max(a,b);
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int ans = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] != 0)
                    ans = max(ans,solve(i,j,m,n,grid,vis));
            }
        }
        return ans;
    }
};





/*


[0,6,0] 
[5,8,7]
[0,9,0]



*/














