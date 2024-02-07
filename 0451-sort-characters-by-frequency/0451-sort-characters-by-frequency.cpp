class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int,char>> v;
        unordered_map<char,int> m;
        for(auto x:s)
            m[x]++;
        for(auto x:m)
            v.push_back({x.second,x.first});
        sort(v.begin(),v.end(),greater<pair<int,int>>());
        string ans;
        for(int i=0;i<v.size();i++)
        {
            while(v[i].first!=0)
            {
                ans+=v[i].second;
                v[i].first--;
            }
        }
        return ans;
    }
};