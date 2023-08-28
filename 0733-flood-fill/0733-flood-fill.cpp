class Solution {
public:
    
    void bfs(int i,int j,vector<vector<int>> &image,vector<vector<int>> &vis,int initialColor,int color,int delRow[],int delCol[])
    {
        queue<pair<int,int>> q;
        vis[i][j]=1;
        image[i][j]=color;
        q.push({i,j});
        int m = image.size();
        int n = image[0].size();
        
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
                if(nrow>=0 and nrow<m and ncol>=0 and ncol<n and image[nrow][ncol]==initialColor and !vis[nrow][ncol])
                {
                    vis[nrow][ncol] = 1;
                    image[nrow][ncol] = color;
                    q.push({nrow,ncol});
                }
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int initialColor = image[sr][sc];
        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,+1,0,-1};
        
        bfs(sr,sc,image,vis,initialColor,color,delRow,delCol);
        return image;
    }
};








































