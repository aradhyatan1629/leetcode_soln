class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<pair<int,int>> adj[n];
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        
        vector<int> dist(n,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        dist[0] = 0;
        pq.push({0,0});
        
        while(!pq.empty())
        {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(dis > dist[node])
                continue;
            for(auto it:adj[node])
            {
                int adjNode = it.first;
                int wt = it.second;
                if(dis+wt < dist[adjNode] && dis+wt < disappear[adjNode])
                {
                    dist[adjNode] = dis+wt;
                    pq.push({dis+wt,adjNode});
                }
            }
        }
        for(auto &x:dist)
        {
            if(x==1e9)
                x=-1;
        }
        return dist;
    }
};


/*
normal dijkstra hi use krna hai 
par imp condition hai ki minimum time to visit
a node from 0 to that node should be less than disappear[of that node]
aur  if(dis > dist[node])continue; condition add hogi to avoid tle.
aur ek imp cheez ki agar multiple components hue bhi graph mein 
to 0 se we cannot reach them isliye unka dist[] to wese hi 1e9 hoga

*/