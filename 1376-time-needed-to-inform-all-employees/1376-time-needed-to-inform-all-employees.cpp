class Solution {
public:
    int ans = 0;
    void dfs(int node,vector<int> &vis,vector<int> adj[],vector<int> &informTime,int &t)
    {
        vis[node]=1;
        t += informTime[node];
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                dfs(it,vis,adj,informTime,t);
            }
        }
        ans = max(ans,t);
        t -= informTime[node];
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> adj[n];int start;
        for(int i=0;i<manager.size();i++)
        {
            if(manager[i]!=-1)
                adj[manager[i]].push_back(i);
            else if(manager[i]==-1)
                start=i;
        }
        vector<int> vis(n,0);int t=0;
        dfs(start,vis,adj,informTime,t);
        return ans;
    }
};