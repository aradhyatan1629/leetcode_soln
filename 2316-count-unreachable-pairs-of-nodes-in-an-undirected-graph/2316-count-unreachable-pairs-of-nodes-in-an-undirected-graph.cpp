class Solution {
public:
    
    void dfs(int start,vector<int> &vis,vector<int> adj[],int &nodeCount)
    {
        vis[start] = 1;
        nodeCount++;
        for(auto it:adj[start])
        {
            if(!vis[it])
            {
                dfs(it,vis,adj,nodeCount);
            }
        }
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> vis(n,0);
        vector<int> adj[n];
        
        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> v;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                int nodeCount=0;
                dfs(i,vis,adj,nodeCount);
                v.push_back(nodeCount);
            }
        }
        long long ans=0;
        long long sum = accumulate(v.begin(),v.end(),0);
        for(int i=0;i<v.size()-1;i++)
        {
            ans += v[i] * (sum-v[i]);
            sum-=v[i];
        }
        return ans;
    }
};

// 4 2 1

