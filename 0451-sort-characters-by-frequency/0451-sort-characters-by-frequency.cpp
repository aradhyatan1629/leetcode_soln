class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> m;
        vector<pair<int,char>> v;
        for(auto x:s)
        {
            m[x]++;
        }
        for(auto x:m)
        {
            v.push_back({x.second,x.first});
        }
        sort(v.begin(),v.end());
        s.clear();
        for(int i=v.size()-1;i>=0;i--)
        {
            while(v[i].first!=0)
            {
                s+=v[i].second;
                v[i].first--;
            }
        }
        return s;
    }
};