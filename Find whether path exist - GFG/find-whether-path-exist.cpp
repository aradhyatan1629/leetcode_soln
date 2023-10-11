//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        pair<int,int> source={-1,-1},destination={-1,-1};
        int n = grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1){source={i,j};}
                else if(grid[i][j]==2){destination={i,j};}
            }
        }
        if(source==make_pair(-1,-1) or destination==make_pair(-1,-1))
        {
            return false;
        }
        
        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,+1,0,-1};
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        queue<pair<int,int>> q;
        vis[source.first][source.second]=1;
        q.push({source.first,source.second});
        
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and !vis[nrow][ncol] and grid[nrow][ncol]==3)
                {
                    vis[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
                else if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and !vis[nrow][ncol] and grid[nrow][ncol]==2)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}
// } Driver Code Ends