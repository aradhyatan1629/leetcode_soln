class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> adj[n];
        for(int i=0;i<roads.size();i++)
        {
            int u=roads[i][0];
            int v=roads[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
        {
            v.push_back({adj[i].size(),i});
        }
        sort(v.begin(),v.end(),greater<pair<int,int>>());
        unordered_map<int,int> m;
        int t=n;
        for(int i=0;i<v.size();i++)
        {
            m[v[i].second] = t;
            t--;
        }
        long long ans=0;
        // for(auto x:m){cout<<x.first<<" "<<x.second<<endl;}
        // for(auto x:v){cout<<x.first<<" "<<x.second<<endl;}
        for(int i=0;i<n;i++)
        {
            for(auto x:adj[i])
            {
                ans+=(m[i]+m[x]);
            }
            // cout<<ans<<endl;
        }
        return ans/2;
    }
};