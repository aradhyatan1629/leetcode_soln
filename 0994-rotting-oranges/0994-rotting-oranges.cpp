class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(),n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<int,pair<int,int>>> q;
        int cntFresh = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2 and !vis[i][j])
                {
                    vis[i][j]=1;
                    q.push({0,{i,j}});
                }
                else if(grid[i][j]==1)
                    cntFresh++;
            }
        }
        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,+1,0,-1};
        int time = 0,cnt=0;
        while(!q.empty())
        {
            int tm = q.front().first;
            time = max(time,tm);
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
                if(nrow>=0 and nrow<m and ncol>=0 and ncol<n and !vis[nrow][ncol] and grid[nrow][ncol]==1)
                {
                    cnt++;
                    vis[nrow][ncol] = 1;
                    q.push({tm+1,{nrow,ncol}});
                }
            }
        }
        if(cntFresh != cnt)
            return -1;
        return time;
    }
};