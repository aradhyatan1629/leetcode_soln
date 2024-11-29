class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> dist(m,vector<int>(n,1e9));
        
        dist[0][0] = 0;
        pq.push({0,{0,0}});
        
        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,+1,0,-1};
        
        while(!pq.empty()){
            int dis = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            
            for(int i=0;i<4;i++){
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
                if(nrow>=0 && nrow<m && ncol>=0 &&ncol<n && dis+grid[nrow][ncol] < dist[nrow][ncol]){
                    dist[nrow][ncol] = dis + grid[nrow][ncol];
                    pq.push({dis+grid[nrow][ncol],{nrow,ncol}});
                }
            }
        }
        return dist[m-1][n-1];
    }
};
/*

0 1 1
1 1 0
1 1 0





*/




