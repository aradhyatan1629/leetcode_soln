class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 or grid[n-1][n-1]==1)
            return -1;
        vector<vector<int>> vis(n,vector<int>(n,0));
        queue<pair<int,pair<int,int>>> q;
        vis[0][0]=1;
        q.push({0,{0,0}});
        
        int delRow[] = {-1,0,+1,0,-1,+1,-1,+1};
        int delCol[] = {0,+1,0,-1,+1,+1,-1,-1};
        
        while(!q.empty())
        {
            int dis = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            if(row==n-1 and col==n-1)
                return dis+1;
            q.pop();
            for(int i=0;i<8;i++)
            {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<n and !vis[nrow][ncol] and grid[nrow][ncol]==0)
                {
                    vis[nrow][ncol]=1;
                    q.push({dis+1,{nrow,ncol}});
                }
            }
        }
        return -1;
    }
};