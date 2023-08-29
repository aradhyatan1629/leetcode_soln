class Solution {
public:
    
    
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>> q;
        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,+1,0,-1};
        
        int cntFresh=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                {
                    vis[i][j] = 2;
                    q.push({{i,j},0});
                }
                else if(grid[i][j]==1)
                {
                    cntFresh++;
                }
            }
        }
        
        int time=0;
        int cnt=0;
        
        while(!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            time = max(time,t);
            q.pop();
            
            for(int i=0;i<4;i++)
            {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
                if(nrow>=0 and nrow<m and ncol>=0 and ncol<n and grid[nrow][ncol]==1 and !vis[nrow][ncol])
                {
                    vis[nrow][ncol] = 2;
                    q.push({{nrow,ncol},t+1});
                    cnt++;
                }
            }
        }
        if(cnt!=cntFresh)
        {
            return -1;
        }
        return time;
    }
};





















