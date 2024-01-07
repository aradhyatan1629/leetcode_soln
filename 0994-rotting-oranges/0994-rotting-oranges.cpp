class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(),n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<int,pair<int,int>>> q; //{time,{row,col}};
        
        int cntFresh = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                {
                    vis[i][j]=1;
                    q.push({0,{i,j}});
                }
                else if(grid[i][j]==1)
                {
                    cntFresh++;
                }
            }
        }
        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,+1,0,-1};
        
        int mxTime = 0,cnt=0;
        while(!q.empty())
        {
            int time = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            mxTime = max(mxTime,time);
            for(int i=0;i<4;i++)
            {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
                if(nrow>=0 and nrow<m and ncol>=0 and ncol<n and !vis[nrow][ncol] and grid[nrow][ncol]==1)
                {
                    vis[nrow][ncol] = 1;
                    q.push({time+1,{nrow,ncol}});
                    cnt++;
                }
            }
        }
        if(cnt!=cntFresh)
            return -1;
        return mxTime;
    }
};