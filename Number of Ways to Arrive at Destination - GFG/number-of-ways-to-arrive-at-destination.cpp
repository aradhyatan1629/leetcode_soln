//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n];
        for(int i=0;i<roads.size();i++)
        {
            int u = roads[i][0];
            int v = roads[i][1];
            int time = roads[i][2];
            adj[u].push_back({v,time});
            adj[v].push_back({u,time});
        }
        
        priority_queue<pair<int,int>,vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<long long> dist(n,LONG_MAX);
        vector<int> ways(n,0);
        
        dist[0]=0;
        ways[0]=1;
        pq.push({0,0});
        
        int mod = (int)(1e9+7);
        
        while(!pq.empty())
        {
            long long dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it:adj[node])
            {
                int adjNode = it.first;
                long long edgeW = it.second;
                if(dis+edgeW < dist[adjNode])
                {
                    dist[adjNode] = dis+edgeW;
                    pq.push({dis+edgeW,adjNode});
                    ways[adjNode] = ways[node];
                }
                else if(dis+edgeW == dist[adjNode])
                {
                    ways[adjNode] = (ways[adjNode] + ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
        
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends