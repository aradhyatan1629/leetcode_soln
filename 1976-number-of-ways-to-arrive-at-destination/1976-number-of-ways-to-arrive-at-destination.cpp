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
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;
        pq.push({0,0});
        
        vector<long long> dist(n,LONG_MAX);
        dist[0]=0;
        
        vector<long long> ways(n,0);
        ways[0]=1;
        
        int mod = (int)(1e9+7);
        
        while(!pq.empty())
        {
            long long dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it:adj[node])
            {
                int adjNode = it.first;
                long long edgeWt = it.second;
                if(dis + edgeWt < dist[adjNode])
                {
                    dist[adjNode] = dis + edgeWt;
                    pq.push({dis+edgeWt,adjNode});
                    ways[adjNode] = ways[node];
                }
                else if(dis+edgeWt == dist[adjNode])
                {
                    ways[adjNode] = (ways[adjNode] + ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};