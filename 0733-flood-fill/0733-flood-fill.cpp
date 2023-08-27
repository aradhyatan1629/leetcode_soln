class Solution {
public:
    void dfs(int row,int col,vector<vector<int>> &image,vector<vector<int>> &vis,int delRow[],int delCol[],int color,int icolor)
    {
        int m=image.size();
        int n=image[0].size();
        vis[row][col] = 1;
        image[row][col] = color;
        for(int i=0;i<4;i++)
        {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if(nrow>=0 and nrow<m and ncol>=0 and ncol<n and image[nrow][ncol]==icolor and !vis[nrow][ncol])
            {
                dfs(nrow,ncol,image,vis,delRow,delCol,color,icolor);
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,+1,0,-1};
        int icolor = image[sr][sc];
        
        dfs(sr,sc,image,vis,delRow,delCol,color,icolor);
        
        return image;
    }
};