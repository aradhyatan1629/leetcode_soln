class Solution {
public:
    //DFS soln-
    void dfs(int node,vector<int> &vis,vector<int> adjList[])
    {
        vis[node]=1;
        for(auto it:adjList[node])
        {
            if(!vis[it])
            {
                dfs(it,vis,adjList);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        int m = isConnected.size();
        int n = isConnected[0].size();
        vector<int> vis(V+1,0);
        vector<int> adjList[V+1];
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j and isConnected[i][j]==1)
                {
                    adjList[i+1].push_back(j+1);
                    adjList[j+1].push_back(i+1);
                }
            }
        }
        int cnt=0;
        for(int i=1;i<=V;i++)
        {
            if(!vis[i])
            {
                cnt++;
                dfs(i,vis,adjList);
            }
        }
        return cnt;
    }
};