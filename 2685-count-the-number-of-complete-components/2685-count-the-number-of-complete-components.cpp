class Solution {
public:
    
    void dfs(int start,vector<int> &vis,vector<int> adj[],int &nodes,int &edges)
    {
        vis[start]=1;
        nodes++;
        edges+=adj[start].size();
        for(auto it:adj[start])
        {
            if(!vis[it])
            {
                dfs(it,vis,adj,nodes,edges);
            }
        }
    }
    
    int countCompleteComponents(int V, vector<vector<int>>& edges) {
        if(edges.size()==0)
        {
            return V;
        }
        int m=edges.size();
        int n=edges[0].size();
        vector<int> vis(V,0);
        vector<int> adj[V];
        
        for(int i=0;i<m;i++)
        {
             int u = edges[i][0];
             int v = edges[i][1];
             adj[u].push_back(v);
             adj[v].push_back(u);
        }
        
        int components=0,errors=0;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                components++;
                int nodes=0,edges=0;
                dfs(i,vis,adj,nodes,edges);
                if(edges!=(nodes*(nodes-1))) errors++;
            }
        }
        return components-errors;;
    }
};