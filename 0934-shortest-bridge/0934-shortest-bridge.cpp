class Solution {
public:
    void dfs(int row,int col,vector<vector<int>> &vis,vector<vector<int>> &grid,int delRow[],int delCol[])
    {
        vis[row][col]=1;
        int n = grid.size();
        for(int i=0;i<4;i++)
        {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if(nrow>=0 and nrow<n and ncol>=0 and ncol<n and !vis[nrow][ncol] and grid[nrow][ncol]==1)
            {
                dfs(nrow,ncol,vis,grid,delRow,delCol);
            }
        }
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> vis(n,vector<int>(n,0));
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,+1,0,-1};
        
        for(int i=0;i<n;i++)
        {
            bool flag=false;
            for(int j=0;j<n;j++)
            {
                if(!vis[i][j] and grid[i][j]==1)
                {
                    dfs(i,j,vis,grid,delRow,delCol);
                    flag=true;
                    break;
                }
            }
            if(flag)
                break;
        }
        
        queue<pair<int,pair<int,int>>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(vis[i][j]==1 and grid[i][j]==1)
                {
                    dist[i][j]=0;
                    q.push({0,{i,j}});
                }
            }
        }
        
        int ans=INT_MAX;
        while(!q.empty())
        {
            int dis = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<n and !vis[nrow][ncol] and grid[nrow][ncol]==1)
                {
                    ans = min(ans,dis);
                }
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<n and dis+1<dist[nrow][ncol] and grid[nrow][ncol]==0)
                {
                    dist[nrow][ncol] = dis+1;
                    q.push({dis+1,{nrow,ncol}});
                }
            }
        }
        return ans;
    }
};


/*

0 1
1 0

0 1 0 
0 0 0
0 0 1





1 1 1 1 1
1 0 0 0 1
1 0 0 0 1
1 0 1 0 1 
1 0 0 0 1
1 0 0 0 1
1 0 0 0 1
1 1 1 1 1


0,1,0,0,0
0,1,0,1,1
0,0,0,0,1
0,0,0,0,0
0,0,0,0,0




*/





























