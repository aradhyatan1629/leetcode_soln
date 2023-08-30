//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,+1,0,-1};
        queue<pair<pair<int,int>,int>> q;
        
        int cntFresh=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                {
                    vis[i][j] = 2;
                    q.push({{i,j},0});
                }
                else if(grid[i][j]==1)
                {
                    cntFresh++;
                }
            }
        }
        
        int cnt=0,time=0;
        while(!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int tm = q.front().second;
            q.pop();
            time = max(time,tm);
            
            for(int i=0;i<4;i++)
            {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
                if(nrow>=0 and nrow<m and ncol>=0 and ncol<n and !vis[nrow][ncol] and grid[nrow][ncol]==1)
                {
                    cnt++;
                    vis[nrow][ncol]=2;
                    q.push({{nrow,ncol},tm+1});
                }
            }
        }
        if(cnt!=cntFresh)
        {
            return -1;
        }
        return time;
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
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends