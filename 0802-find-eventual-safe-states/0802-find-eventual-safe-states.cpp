class Solution {
public:
    
    bool dfs(int node,vector<int> &vis,vector<int> &pathvis,vector<int> &check,vector<int> adj[])
    {
        vis[node]=1;
        pathvis[node]=1;
        check[node]=0;
        
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                if(dfs(it,vis,pathvis,check,adj))
                {
                    check[it]=0;
                    return true;
                }
            }
            else if(vis[it]==1 and pathvis[it]==1)
            {
                check[it]=0;
                return true;
            }
        }
        check[node]=1;
        pathvis[node]=0;
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> adj[V];
        vector<int> vis(V,0);
        vector<int> pathvis(V,0);
        vector<int> check(V,0);
        
        for(int i=0;i<graph.size();i++)
        {
            adj[i]=graph[i];
        }
        
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                dfs(i,vis,pathvis,check,adj);
            }
        }
        
        vector<int> safeNodes;
        for(int i=0;i<check.size();i++)
        {
            if(check[i]==1)
            {
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    }
};