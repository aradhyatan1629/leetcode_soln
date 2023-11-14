class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        vector<int> vis(n,0);
        vector<int> adj[n];
        
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        for(int i=0;i<n;i++)
        {
            for(auto it:adj[i])
            {
                vis[it]=1;
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
                ans.push_back(i);
        }
        return ans;
    }
};