class Solution {
public:   
/*
Intuition - 
Bfs, 
that is from each 0 we will move in the 4 directions and if 
we get a 1 in any of the 4 direction then that 1 is at a distance of 1
again we will go in 4 directions from these 1(which are at a distance of 1) , 
now any 1 found now will be at a distance of 2 , and so on.
*/
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dist(m,vector<int>(n,0));    //answer matrix
        vector<vector<int>> vis(m,vector<int>(n,0));     //visited matrix
        queue<pair<pair<int,int>,int>> q;                //{{row,col},distance}
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j] == 0)
                {
                    vis[i][j] = 1;
                    q.push({{i,j},0});
                }
            }
        }
        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,+1,0,-1};
        while(!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int distance = q.front().second;
            q.pop();
            dist[row][col] = distance;
            
            for(int i=0;i<4;i++)
            {
                int nrow = row+delRow[i];
                int ncol = col+delCol[i];
                if(nrow>=0 and nrow<m and ncol>=0 and ncol<n and vis[nrow][ncol]==0)
                {
                    vis[nrow][ncol] = 1;
                    q.push({{nrow,ncol},distance+1});
                }
            }
        }
        return dist;
    }
};
