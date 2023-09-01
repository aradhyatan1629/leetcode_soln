class Solution {
public:
    
    void dfs(int node,vector<int> &vis,vector<int> adj[],unordered_map<int,int> &m,int &cnt)
    {
        vis[node] = 1;
        for(auto it:adj[node])
        {
            if(!vis[it] and m[it]!=1)
            {
                cnt++;
                dfs(it,vis,adj,m,cnt);
            }
        }
    }
    
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<int> adj[n];
        vector<int> vis(n,0);
        
        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        unordered_map<int,int> m;
        for(auto x:restricted)
        {
            m[x] = 1;
        }
        
        int cnt=1;
        dfs(0,vis,adj,m,cnt);
        return cnt;
    }
};