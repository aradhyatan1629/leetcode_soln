class Solution {
public:
    int dijkstra(int source,int target,vector<pair<int,int>> adj[],vector<vector<int>> &memo)
    {
        if(memo[source][target]!=-1)
            return memo[source][target];
        vector<int> dist(26,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        dist[source] = 0;
        pq.push({0,source});
        
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
                    dist[adjNode] = dis+adjWt;
                    pq.push({dis+adjWt,adjNode});
                }
            }
        }
        if(dist[target] == 1e9)
            return -1;
        return memo[source][target] = dist[target];
    }
    
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<pair<int,pair<char,char>>> v;
        for(int i=0;i<original.size();i++)
        {
            v.push_back({cost[i],{original[i],changed[i]}});
        }
        sort(v.begin(),v.end());
        
        vector<pair<int,int>> adj[26];
        adj[v[0].second.first-'a'].push_back({v[0].second.second-'a',v[0].first});
        
        for(int i=1;i<v.size();i++)
        {
            int wt = v[i].first;
            int u = v[i].second.first-'a';
            int w = v[i].second.second-'a';
            adj[u].push_back({w,wt});
        }
        
        long long ans = 0;
        vector<vector<int>> memo(26,vector<int>(26,-1));
        for(int i=0;i<source.size();i++)
        {
            if(source[i] != target[i])
            {
                int mnDist = dijkstra(source[i]-'a',target[i]-'a',adj,memo);
                if(mnDist == -1)
                    return -1;
                ans += mnDist;
            }
        }
        return ans;
    }
};