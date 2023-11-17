class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int,double>> adj[n];
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        priority_queue<pair<double,int>> pq;
        vector<double> dist(n,1e-9);
        
        dist[start] = 1.0;
        pq.push({1.0,start});
        
        while(!pq.empty())
        {
            int node = pq.top().second;
            double dis = pq.top().first;
            pq.pop();
            
            for(auto it:adj[node])
            {
                int adjNode = it.first;
                double edgeWt = it.second;
                if(dis * edgeWt > dist[adjNode])
                {
                    dist[adjNode] = dis*edgeWt;
                    pq.push({dis*edgeWt,adjNode});
                }
            }
        }
        if(dist[end]==1e-9)
            return 0;
        return dist[end];
    }
};