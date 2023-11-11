class Graph {
public:
    vector<pair<int,int>> adj[101];
    int t;
    Graph(int n, vector<vector<int>>& edges) {
        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v,wt});
        }
        t=n;
    }
    
    void addEdge(vector<int> edge) {
        int u=edge[0],v=edge[1],wt=edge[2];
        adj[u].push_back({v,wt});
    }
    
    int shortestPath(int node1, int node2) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(t,1e9);
        
        pq.push({0,node1});
        dist[node1]=0;
        
        while(!pq.empty())
        {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it:adj[node])
            {
                int edgeWeight = it.second;
                int adjNode = it.first;
                if(dis+edgeWeight < dist[adjNode])
                {
                    dist[adjNode] = dis+edgeWeight;
                    pq.push({dis+edgeWeight,adjNode});
                }
            }
        }
        if(dist[node2]==1e9)return -1;
        return dist[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */