class Solution {
public:
    void dfs(int node,vector<int> adj[],vector<int> &vis)
    {
        vis[node] = 1;
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                dfs(it,adj,vis);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<int> adj[V+1];    
        
        for(int i=0;i<V;i++)        //converting give adj matrix to adj list
        {
            for(int j=0;j<V;j++)
            {
                if(isConnected[i][j]==1 and i!=j)
                {
                    adj[i+1].push_back(j+1);
                    adj[j+1].push_back(i+1);
                }
            }
        }
        vector<int> vis(V+1,0);
        int cnt=0;
        for(int i=1;i<=V;i++)
        {
            if(vis[i]==0)
            {
                cnt++;
                dfs(i,adj,vis);
            }
        }
        return cnt;
    }
};