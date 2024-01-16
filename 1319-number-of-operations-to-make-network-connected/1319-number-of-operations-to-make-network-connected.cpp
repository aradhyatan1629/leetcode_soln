class Solution {
public:
    void dfs(int node,vector<int> &vis,vector<int> adj[],int &edges)
    {
        vis[node]=1;
        edges+=adj[node].size();
        for(auto it:adj[node])
        {
            if(!vis[it])
                dfs(it,vis,adj,edges);
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(int i=0;i<connections.size();i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        vector<int> vis(n,0);
        int edges=0,components=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                components++;
                dfs(i,vis,adj,edges);
            }
        }
        edges/=2;
        if(edges < n-1)
            return -1;
        return components-1;
    }
};


/*

count the no. of edges and components
if(edges < compontents-1)return -1





*/