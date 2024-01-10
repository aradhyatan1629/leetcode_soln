class Solution {
public:
    void bfs(int i,vector<int> adj[],vector<vector<int>> &canReach,int n)
    {
        vector<int> vis(n,0);
        queue<int> q;
        vis[i]=1;
        q.push(i);
        while(!q.empty())
        {
            int node = q.front();q.pop();
            for(auto it:adj[node])
            {
                if(!vis[it])
                {
                    canReach[i][it] = 1;
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        if(prerequisites.size() == 0)
            return vector<bool> (queries.size(),false);
        int n = numCourses;
        vector<int> adj[n];
        for(int i=0;i<prerequisites.size();i++)
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        
        vector<vector<int>> canReach(n,vector<int>(n,0));
        for(int i=0;i<n;i++)
        {
            bfs(i,adj,canReach,n);
        }
        vector<bool> ans;
        for(int i=0;i<queries.size();i++)
        {
            if(canReach[queries[i][0]][queries[i][1]]==1)
                ans.push_back(true);
            else
                ans.push_back(false);
        }
        return ans;
    }
};