class Solution {
public:
    
    bool bfs(int node,vector<int> &color,vector<int> adj[])
    {
        queue<int> q;
        q.push(node);
        color[node]=0;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(auto it:adj[node])
            {
                if(color[it]==-1)
                {
                    color[it]=!color[node];
                    q.push(it);
                }
                else if(color[it]==color[node])
                {
                    return false;
                }
            }
        }
        return true;
    }
    
    bool possibleBipartition(int V, vector<vector<int>>& dislikes) {
        // int m = dislikes.size(),n=dislikes[0].size();
        int m = dislikes.size();
        int n = (m > 0) ? dislikes[0].size() : 0;
        vector<int> color(V+1,-1);
        vector<int> adj[V+1];
        
        for(int i=0;i<m;i++)
        {
            int u=dislikes[i][0];
            int v=dislikes[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        for(int i=1;i<=V;i++)
        {
            if(color[i]==-1)
            {
                if(!bfs(i,color,adj))
                {
                    return false;
                }
            }
        }
        return true;
    }
};