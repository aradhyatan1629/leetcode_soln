class Solution {
public:
    
    vector<vector<int>> ans;
    void dfs(int node,vector<int> &vis,vector<vector<int>> &adj,vector<int> &v,int n)
    {
        vis[node]=1;
        v.push_back(node);
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                dfs(it,vis,adj,v,n);
            }
        }
        if(node == n-1)
            ans.push_back(v);
        vis[node]=0;
        v.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n,0);
        vector<int> v;
        dfs(0,vis,graph,v,n);
        return ans;
    }
};