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
                    return true;
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
        int n = numCourses;
        vector<int> adj[n];
        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> vis(n,0),pathvis(n,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                if(dfs(i,vis,pathvis,adj))
                    return false;
            }
        }
        return true;
    }
};