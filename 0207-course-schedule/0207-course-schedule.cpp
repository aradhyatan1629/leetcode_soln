class Solution {
public:
    
    bool dfs(int node,vector<int> &vis,vector<int> &pathvis,vector<int> adj[])
    {
        vis[node]=1;
        pathvis[node]=1;
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                if(dfs(it,vis,pathvis,adj))
                {
                    return true;
                }
            }
            else if(vis[it]==1 and pathvis[it]==1)
            {
                return true;
            }
        }
        pathvis[node]=0;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        vector<int> adj[V];
        vector<int> vis(V,0);
        vector<int> pathvis(V,0);
        
        for(int i=0;i<prerequisites.size();i++)
        {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[u].push_back(v);
        }
        
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(dfs(i,vis,pathvis,adj))
                {
                    return false;
                }
            }
        }
        return true;
    }
};