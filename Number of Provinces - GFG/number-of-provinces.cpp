//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    
    void bfs(int node,vector<int> adjList[],vector<int> &vis)
    {
        vis[node]=1;
        queue<int> q;
        q.push(node);
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(auto it:adjList[node])
            {
                if(!vis[it])
                {
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
    }
  
    int numProvinces(vector<vector<int>> adj, int V) {
        int m = adj.size(),n=adj[0].size();
        vector<int> vis(V+1,0);
        vector<int> adjList[V+1];
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(adj[i][j]==1 and i!=j)
                {
                    adjList[i+1].push_back(j+1);
                    adjList[j+1].push_back(i+1);
                }
            }
        }
        int start=1;
        int cnt=0;
        
        for(int i=1;i<=V;i++)
        {
            if(!vis[i])
            {
                cnt++;
                bfs(i,adjList,vis);
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