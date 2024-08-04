class Solution {
public:
    int dijkstra(int n,vector<pair<int,int>> adj[])
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(n,1e9);
        dist[0] = 0;
        pq.push({0,0});
        while(!pq.empty())
        {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it:adj[node])
            {
                int adjNode = it.first;
                int adjWt = it.second;
                if(dis + adjWt < dist[adjNode])
                {
                    dist[adjNode] = dis + adjWt;
                    pq.push({dis+adjWt,adjNode});
                }
            }
        }
        return dist[n-1];
    }
    
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        vector<pair<int,int>> adj[n];
        for(int i=0;i<n-1;i++)
        {
            adj[i].push_back({i+1,1});
        }
        for(int i=0;i<queries.size();i++)
        {
            adj[queries[i][0]].push_back({queries[i][1],1});
            ans.push_back(dijkstra(n,adj));
        }
        return ans;
    }
};