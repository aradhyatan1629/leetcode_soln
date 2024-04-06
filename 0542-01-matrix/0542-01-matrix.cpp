class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<int,pair<int,int>>> q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!vis[i][j] and mat[i][j]==0)
                {
                    vis[i][j]=1;
                    q.push({0,{i,j}});
                }
            }
        }
        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,+1,0,-1};
        while(!q.empty())
        {
            int dist = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
                if(nrow>=0 and nrow<m and ncol>=0 and ncol<n and !vis[nrow][ncol] and mat[nrow][ncol]==1)
                {
                    vis[nrow][ncol] = dist+1;
                    q.push({dist+1,{nrow,ncol}});
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==0)
                    vis[i][j]=0;
            }
        }
        return vis;
    }
};