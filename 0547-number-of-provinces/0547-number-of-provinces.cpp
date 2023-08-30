class Solution {
public:
    //BFS soln - 
    void bfs(int node,vector<int> adjList[],vector<int> &vis)
    {
        queue<int> q;
        vis[node]=1;
        q.push(node);
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(auto it:adjList[node])
            {
                if(!vis[it])
                {
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int m = isConnected.size();
        int n = isConnected[0].size();
        vector<int> vis(m+1);
        vector<int> adjList[m+1];
        
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
        for(int i=1;i<=m;i++)
        {
            if(!vis[i])
            {
                cnt++;
                bfs(i,adjList,vis);
            }
        }
        return cnt;
    }
};