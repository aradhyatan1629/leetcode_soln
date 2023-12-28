class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<long long> adj[n];
        for(int i=0;i<edges.size();i++)
        {
            adj[i].push_back(edges[i]);
        }
        
        vector<long long> v(n,0);
        for(int i=0;i<n;i++)
        {
            for(auto x:adj[i])
            {
                v[x]+=i;
            }
        }
        long long mx = 0;
        for(auto x:v)
            mx = max(mx,x);
        for(int i=0;i<v.size();i++)
        {
            if(v[i]==mx)
                return i;
        }
        return 0;
    }
};