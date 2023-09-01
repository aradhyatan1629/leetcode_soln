class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>> q;      //stores {{row,col},time}
        
        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,+1,0,-1};
        
        int cntFresh = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 2)    //if orange is rotten
                {
                    vis[i][j] = 2;    //mark the oranges as rotten in the visited array
                    q.push({{i,j},0});
                }
                else if(grid[i][j] == 1)
                {
                    cntFresh++;
                }
            }
        }
        
        int time=0,cnt=0;
        while(!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int tm = q.front().second;
            time = max(time,tm);
            q.pop();
            
            for(int i=0;i<4;i++)
            {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
                if(nrow>=0 and nrow<m and ncol>=0 and ncol<n and vis[nrow][ncol]!=2 and grid[nrow][ncol]==1)
                {
                    cnt++;
                    vis[nrow][ncol]=2;
                    q.push({{nrow,ncol},tm+1}); // push in queue with timer increased
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