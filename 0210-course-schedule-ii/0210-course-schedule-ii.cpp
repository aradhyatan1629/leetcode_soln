class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> adj[n];
        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> indegree(n,0);
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            for(auto it:adj[i])
                indegree[it]++;
        }
        for(int i=0;i<indegree.size();i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        vector<int> ans;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
        }
        if(ans.size()!=n)
            return {};
        return ans;
    }
};