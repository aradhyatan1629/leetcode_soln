class Solution {
public:
    
    void dfs(int node,vector<int> &vis,vector<int> adj[])
    {
        vis[node]=1;
        for(auto it:adj[node])
        {
            if(!vis[it])
                dfs(it,vis,adj);
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n+1];
        for(int i=0;i<isConnected.size();i++)
        {
            for(int j=0;j<isConnected[i].size();j++)
            {
                if(isConnected[i][j] == 1)
                {
                    adj[i+1].push_back(j+1);
                    adj[j+1].push_back(i+1);
                }
            }
        }
        vector<int> vis(n+1,0);
        int ans = 0;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                ans++;
                dfs(i,vis,adj);
            }
        }
        return ans;
    }
};