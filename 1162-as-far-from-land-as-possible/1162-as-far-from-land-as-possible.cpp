class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<int,pair<int,int>>> q;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 1)
                {
                    vis[i][j]=1;
                    q.push({0,{i,j}});
                }
            }
        }
        
        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,+1,0,-1};
        int ans = 0;
        
        while(!q.empty())
        {
            int dist = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            ans = max(ans,dist);
            
            for(int i=0;i<4;i++)
            {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
                if(nrow>=0 and nrow<m and ncol>=0 and ncol<n and !vis[nrow][ncol] and grid[nrow][ncol]==0)
                {
                    vis[nrow][ncol]=1;
                    q.push({dist+1,{nrow,ncol}});
                }
            }
        }
        ans = (ans==0)?-1:ans;
        return ans;
    }
};