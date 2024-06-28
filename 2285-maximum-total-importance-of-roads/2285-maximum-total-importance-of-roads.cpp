class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> adj[n];
        for(int i=0;i<roads.size();i++)
        {
            adj[roads[i][0]].push_back(roads[i][1]);
            adj[roads[i][1]].push_back(roads[i][0]);
        }
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
        {
            v.push_back({adj[i].size(),i});
        }
        sort(v.begin(),v.end(),greater<pair<int,int>>());
        unordered_map<int,int> m;
        int t = n;
        for(int i=0;i<v.size();i++)
        {
            m[v[i].second] = t;
            t--;
        }
        long long ans = 0;
        for(int i=0;i<n;i++)
        {
            for(auto x:adj[i])
            {
                ans+=(m[i]+m[x]);
            }
        }
        return ans/2;
    }
};