class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(int i=0;i<times.size();i++)
        {
            adj[times[i][0]].push_back({times[i][2],times[i][1]});
        }
        
        vector<int> dist(n+1,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        dist[k]=0;
        pq.push({0,k});
        
        while(!pq.empty())
        {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it:adj[node])
            {
                int edgeWt = it.first;
                int adjNode = it.second;
                if(dis + edgeWt < dist[adjNode])
                {
                    dist[adjNode] = dis+edgeWt;
                    pq.push({dis+edgeWt,adjNode});
                }
            }
        }
        int mn=-1;
        for(int i=1;i<dist.size();i++)
        {
            mn = max(mn,dist[i]);
        }
        if(mn==1e9)
            return -1;
        return mn;
    }
};