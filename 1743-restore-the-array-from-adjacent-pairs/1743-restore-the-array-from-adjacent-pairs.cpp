class Solution {
public:
    
    void dfs(int i, unordered_map<int, int>& vis, vector<int>& ans, unordered_map<int, vector<int>>& adj) {
        vis[i] = 1;
        ans.push_back(i);
        for (auto it : adj[i]) {
            if (!vis[it]) {
                dfs(it, vis, ans, adj);
            }
        }
    }
    
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        vector<int> ans;
        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> vis;

        int mx = INT_MIN;

        for (const auto& pair : adjacentPairs) {
            adj[pair[0]].push_back(pair[1]);
            adj[pair[1]].push_back(pair[0]);
            mx = max(mx, max(pair[0], pair[1]));
        }
    
        int start;
        for(auto x:adj)
        {
            if(x.second.size()==1)
            {
                start=x.first;
                break;
            }
        }
        dfs(start,vis,ans,adj);
        return ans;
    }
};
