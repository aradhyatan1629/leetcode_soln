//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        if(A[0][0]==0 or A[X][Y]==0){return -1;}
        vector<vector<int>> dist(N,vector<int>(M,1e9));
        dist[0][0] = 0;
        
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{0,0}});
        
        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,+1,0,-1};
        
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int steps = it.first;
            int row = it.second.first;
            int col = it.second.second;
            
            for(int i=0;i<4;i++)
            {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
                if(nrow>=0 and nrow<N and ncol>=0 and ncol<M and steps+1<dist[nrow][ncol] and A[nrow][ncol]==1)
                {
                    dist[nrow][ncol] = steps+1;
                    q.push({steps+1,{nrow,ncol}});
                }
            }
        }
        if(dist[X][Y]==1e9){return -1;}
        return dist[X][Y];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends