class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1)
            return 1;
        vector<int> adj[n+1];
        for(int i=0;i<trust.size();i++)
        {
            adj[trust[i][0]].push_back(trust[i][1]);
        }
        unordered_map<int,int> m;
        for(int i=1;i<=n;i++)
        {
            for(auto it:adj[i])
                m[it]++;
        }
        for(auto x:m)
        {
            if(x.second==n-1 and adj[x.first].size()==0)
                return x.first;
        }
        return -1;
    }
};