class Solution {
public:
    /*
    We need to find if there exists a cycle or not if there is a cycle we cannot complete all the tasks or else we can. To find a cycle use dfs or bfs(Topological sort)
    */
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        vector<int> adj[V];
        vector<int> indegree(V,0);
        
        for(int i=0;i<prerequisites.size();i++)
        {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[u].push_back(v);
        }
        
        for(int i=0;i<V;i++)
        {
            for(auto x:adj[i])
            {
                indegree[x]++;
            }
        }
        queue<int> q;
        int cnt=0;
        for(int i=0;i<indegree.size();i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            cnt++;
            for(auto it:adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                {
                    q.push(it);
                }
            }
        }
        if(cnt==V)
        {
            return true;
        }
        return false;
    }
};