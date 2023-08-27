class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cntfresh=0;
        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>> q;   // store {{row, column}, time}
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)// if cell contains rotten orange
                {
                    q.push({{i,j},0});
                    vis[i][j]=2;// mark as visited (rotten) in visited array
                }
                else if(grid[i][j]==1)
                {
                    cntfresh++;
                }
            }
        }
        int time=0;
        int cnt=0;
        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,+1,0,-1};
        
        while(!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            time = max(t,time);
            q.pop();
            
            for(int i=0;i<4;i++)
            {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
                if(nrow>=0 and nrow<m and ncol>=0 and ncol<n and grid[nrow][ncol]==1 and !vis[nrow][ncol])
                {
                    vis[nrow][ncol]=2;
                    q.push({{nrow,ncol},t+1});  // push in queue with timer increased
                    cnt++;
                }
            }
        }
        if(cntfresh!=cnt)
        {
            return -1;
        }
        return time;
    }
};