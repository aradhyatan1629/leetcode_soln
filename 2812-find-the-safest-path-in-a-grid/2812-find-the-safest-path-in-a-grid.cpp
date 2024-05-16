class Solution {
public:
   bool check(vector<vector<int>> &dist,int sf,int delRow[],int delCol[])
   {
       int m=dist.size(),n=dist[0].size();
       vector<vector<int>> vis(m,vector<int>(n,0));
       queue<pair<int,int>> q;
       
       vis[0][0] = 1;
       q.push({0,0});
       
       if(dist[0][0] < sf)
            return false;
       
       while(!q.empty())
       {
           int row = q.front().first;
           int col = q.front().second;
           q.pop();
           if(row==m-1 && col==n-1)
               return true;
           for(int i=0;i<4;i++)
           {
               int nrow = row + delRow[i];
               int ncol = col + delCol[i];
               if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol] && dist[nrow][ncol]>=sf)
               {
                   vis[nrow][ncol]=1;
                   q.push({nrow,ncol});
               }
           }
       }
       return false;
   }
    
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> dist(m,vector<int>(n,0)),vis(m,vector<int>(n,0));
        queue<pair<int,pair<int,int>>> q;
      
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    dist[i][j] = 0;
                    vis[i][j] = 1;
                    q.push({0,{i,j}});
                }
            }
        }
        
        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,+1,0,-1};
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
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol]==0 && !vis[nrow][ncol])
                {
                    vis[nrow][ncol] = 1;
                    dist[nrow][ncol] = dis+1;
                    q.push({dis+1,{nrow,ncol}});
                }
            }
        }
       
        int ans = 0;
        int low =  0;
        int high = 400;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(check(dist,mid,delRow,delCol))
            {
                ans = mid;
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }
        return ans;
    }
};




