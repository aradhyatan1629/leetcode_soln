class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        vector<vector<int>> dis(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>> q;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==0)
                {
                    vis[i][j] = 1;
                    q.push({{i,j},0});
                }
                else
                {
                    vis[i][j] = 0;
                }
            }
        }
        while(!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int distance = q.front().second;
            q.pop();
            
            dis[row][col] = distance;
            
            int delRow[] = {-1,0,+1,0};
            int delCol[] = {0,+1,0,-1};
            for(int i=0;i<4;i++)
            {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
                if(nrow>=0 and nrow<m and ncol>=0 and ncol<n and vis[nrow][ncol]==0)
                {
                    vis[nrow][ncol] = 1;
                    q.push({{nrow,ncol},distance+1});
                }
            }
        }
        return dis;
    }
};