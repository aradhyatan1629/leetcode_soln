class Solution {
public:
    void bfs(int source,vector<pair<int,int>> adj[],int distanceThreshold,int &city,int n)
    {
        unordered_map<int,int> m;
        vector<int> dist(n,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        dist[source]=0;
        pq.push({0,source});
        m[source]=1;
        while(!pq.empty())
        {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it:adj[node])
            {
                int adjNode = it.first;
                int adjDist = it.second;
                if(dis+adjDist<dist[adjNode] and dis+adjDist<=distanceThreshold)
                {
                    if(m.find(adjNode)==m.end())city++;
                    dist[adjNode] = dis + adjDist;
                    pq.push({dis+adjDist,adjNode});
                    m[adjNode]=1;
                }
            }
        }
    }
    
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<pair<int,int>> adj[n];
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        int ans = -1;
        int mnCities = INT_MAX;
        
        for(int i=0;i<n;i++)
        {
            int city=0;
            bfs(i,adj,distanceThreshold,city,n);
            if(city <= mnCities){mnCities=city;ans=i;}
        }
        return ans;
    }
};