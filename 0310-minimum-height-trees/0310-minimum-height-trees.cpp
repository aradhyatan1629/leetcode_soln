class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==0)
            return {};
        if(n==1)
            return {0};
        vector<int> adj[n];
        vector<int> indegree(n,0);
        queue<int> q;
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0],v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            indegree[u]++;
            indegree[v]++;
        }
        for(int i=0;i<indegree.size();i++)
        {
            if(indegree[i]==1)
                q.push(i);
        }
        vector<int> ans;
        while(!q.empty())
        {
            ans.clear();
            int sz = q.size();
            for(int i=0;i<sz;i++)
            {
                int node = q.front();
                ans.push_back(node);
                q.pop();
                for(auto it:adj[node])
                {
                    indegree[it]--;
                    if(indegree[it]==1)
                        q.push(it);
                }
            }
        }
        return ans;
    }
};