class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(int i=0;i<flights.size();i++)
        {
            int u = flights[i][0];
            int v = flights[i][1];
            int cost = flights[i][2];
            adj[u].push_back({v,cost});
        }
        
        queue<pair<int,pair<int,int>>> q;
        vector<int> dist(n,1e9);
        
        dist[src]=0;
        q.push({0,{src,0}});
        
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;
            
            if(stops>k)
            {
                continue;
            }
            for(auto iter:adj[node])
            {
                int adjNode = iter.first;
                int edgeWt = iter.second;
                if((cost + edgeWt < dist[adjNode]) and stops<=k)
                {
                    dist[adjNode] = cost+edgeWt;
                    q.push({stops+1,{adjNode,cost+edgeWt}});
                }
            }
        }
        if(dist[dst]==1e9){return -1;}
        return dist[dst];
    }
};