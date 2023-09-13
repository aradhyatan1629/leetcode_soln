//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    
    void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<int>> &grid,int delRow[],int delCol[],int &cnt)
    {
        vis[row][col] = 1;
        int n = grid.size(),m=grid[0].size();
        for(int i=0;i<8;i++)
        {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and !vis[nrow][ncol] and grid[nrow][ncol]==1)
            {
                cnt++;
                dfs(nrow,ncol,vis,grid,delRow,delCol,cnt);
            }
        }
    }
    
    int findMaxArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int mx=0;
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        int delRow[] = {-1,0,+1,0,+1,-1,+1,-1};
        int delCol[] = {0,+1,0,-1,+1,-1,-1,+1};
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 and !vis[i][j])
                {
                    int cnt=1;
                    dfs(i,j,vis,grid,delRow,delCol,cnt);
                    mx = max(mx,cnt);
                }
            }
        }
        return mx;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends