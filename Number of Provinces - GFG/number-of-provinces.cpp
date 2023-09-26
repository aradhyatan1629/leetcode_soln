//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    
    void dfs(int node,vector<int> &vis,vector<int> adjList[])
    {
        vis[node]=1;
        for(auto it:adjList[node])
        {
            if(!vis[it])
            {
                dfs(it,vis,adjList);
            }
        }
    }
  
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int> adjList[V+1];
        int m = adj.size(),n=adj[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j and adj[i][j]==1)
                {
                    adjList[i+1].push_back(j+1);
                    adjList[j+1].push_back(i+1);
                }
            }
        }
        int cnt=0;
        vector<int> vis(V+1,0);
        for(int i=1;i<=V;i++)
        {
            if(!vis[i])
            {
                cnt++;
                dfs(i,vis,adjList);
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends