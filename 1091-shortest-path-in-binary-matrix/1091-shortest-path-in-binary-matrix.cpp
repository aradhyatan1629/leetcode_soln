class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0]!=0)
        {
            return -1;
        }
        
        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        
        dist[0][0] = 1;
        q.push({1,{0,0}});
        
        int delRow[] = {-1,0,+1,0,-1,+1,-1,+1};
        int delCol[] = {0,+1,0,-1,+1,+1,-1,-1};
        
        while(!q.empty())
        {
            int dis = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            
            for(int i=0;i<8;i++)
            {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
                
                
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<n and grid[nrow][ncol]==0 and dis+1<dist[nrow][ncol])
                {
                    dist[nrow][ncol] = 1 + dis;
                    q.push({dis+1,{nrow,ncol}});
                }
            }
        }
        if(dist[n-1][n-1]==1e9){return -1;}
        return dist[n-1][n-1];
    }
};