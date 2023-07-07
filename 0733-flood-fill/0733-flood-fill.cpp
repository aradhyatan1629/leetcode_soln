class Solution {
public:
    
    void dfs(vector<vector<int>> &image,int i,int j,int initialColor,int newColor)
    {
        if(i<0 or i>=image.size() or j<0 or j>=image[0].size() or image[i][j]==newColor or                   image[i][j]!=initialColor)
        {
            return;
        }
        image[i][j] = newColor;
        dfs(image,i-1,j,initialColor,newColor);
        dfs(image,i+1,j,initialColor,newColor);
        dfs(image,i,j-1,initialColor,newColor);
        dfs(image,i,j+1,initialColor,newColor);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColor = image[sr][sc];
        dfs(image,sr,sc,initialColor,color);
        return image;
    }
};