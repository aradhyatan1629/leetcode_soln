class Solution {
public:
    
    void dfs(int i,int j,vector<vector<int>> &vis,vector<vector<int>> &land,int delRow[],int delCol[],int &x2,int &y2)
    {
        vis[i][j] = 1;
        int row=i;
        int col=j;
        int m = land.size();
        int n = land[0].size();
        for(int i=0;i<4;i++)
        {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if(nrow>=0 and nrow<m and ncol>=0 and ncol<n and land[nrow][ncol]==1 and !vis[nrow][ncol])
            {
                x2 = max(x2,nrow);
                y2 = max(y2,ncol);
                dfs(nrow,ncol,vis,land,delRow,delCol,x2,y2);
            }
        }
    }
    
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size();
        int n = land[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        vector<vector<int>> ans;
        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,+1,0,-1};
        
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(land[i][j]==1 and !vis[i][j])
                {
                    int x1=i,y1=j,x2=i,y2=j;
                    dfs(i,j,vis,land,delRow,delCol,x2,y2);
                    ans.push_back({x1,y1,x2,y2});
                }
            }
        }
        return ans;
    }
};