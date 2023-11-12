//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    void dfs(int row,int col,vector<vector<int>> &vis,vector<vector<char>> &grid,int delRow[],int delCol[])
    {
        vis[row][col]=1;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<8;i++)
        {
            int nrow = row+delRow[i];
            int ncol = col+delCol[i];
            if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and !vis[nrow][ncol] and grid[nrow][ncol]=='1')
            {
                dfs(nrow,ncol,vis,grid,delRow,delCol);
            }
        }
    }
    
    
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        int delRow[] = {-1,0,+1,0,-1,+1,-1,+1};
        int delCol[] = {0,+1,0,-1,+1,+1,-1,-1};
        
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' and !vis[i][j])
                {
                    cnt++;
                    dfs(i,j,vis,grid,delRow,delCol);
                }
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends