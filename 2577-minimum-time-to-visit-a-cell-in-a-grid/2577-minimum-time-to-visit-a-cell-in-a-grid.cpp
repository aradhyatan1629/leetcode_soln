class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        if(grid[0][1] > 1 && grid[1][0] > 1)
            return -1;
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, 
        greater<pair<int,pair<int,int>>>> pq; //{time,{i,j}}
        vector<vector<int>> time(m,vector<int>(n,1e9));
        
        time[0][0] = 0;
        pq.push({0,{0,0}});
        
        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,+1,0,-1};
        
        while(!pq.empty()){
            int tm = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            
            for(int i=0;i<4;i++){
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n){
                    int timeDiff = grid[nrow][ncol] - tm;
                    if(timeDiff <= 0){
                        if(tm + 1 < time[nrow][ncol]){
                            time[nrow][ncol] = tm+1;
                            pq.push({tm+1,{nrow,ncol}});
                        }
                    }
                    else if(timeDiff%2 == 0){
                        if(grid[nrow][ncol] + 1 < time[nrow][ncol]){
                            time[nrow][ncol] = grid[nrow][ncol]+1;
                            pq.push({grid[nrow][ncol]+1,{nrow,ncol}});
                        }
                    }
                    else{
                        if(grid[nrow][ncol]  < time[nrow][ncol]){
                            time[nrow][ncol] = grid[nrow][ncol];
                            pq.push({grid[nrow][ncol],{nrow,ncol}});
                        }
                    }
                }
            }
        }
        return time[m-1][n-1];
    }
};