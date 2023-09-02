//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    void dfs(int row,int col,vector<vector<int>> &vis,vector<vector<char>> &mat,int delRow[],int delCol[])
    {
        vis[row][col] = 1;
        int n = mat.size();
        int m = mat[0].size();
        for(int i=0;i<4;i++)
        {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and !vis[nrow][ncol] and mat[nrow][ncol]=='O')
            {
                dfs(nrow,ncol,vis,mat,delRow,delCol);
            }
        }
    }

    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<int>> vis(n,vector<int>(m,0));
        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,+1,0,-1};
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if((i==0 or i==n-1 or j==0 or j==m-1) and (!vis[i][j] and mat[i][j]=='O'))
                {
                    dfs(i,j,vis,mat,delRow,delCol);
                }
            }
        }
        
        vector<vector<char>> ans = mat;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(ans[i][j]=='O' and vis[i][j]!=1)
                {
                    ans[i][j] = 'X';
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends