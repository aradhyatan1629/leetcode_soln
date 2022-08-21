class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> ans;
        vector<pair<int,int>> v;
        int n=s.size();
        int i=0,j=0;
        for(i=0;i<n-1;++i)
        {
            int cnt=1;
            for(j=i+1;j<n;j++)
            {
                if(s[i]==s[j])
                {
                    cnt++;
                }
                else
                {
                    break;
                }
            }
            if(cnt>=3)
            {
                v.push_back({i,j-1});
                i=j-1;
            }
        }
        sort(v.begin(),v.end());
        for(auto x:v)
        {
            vector<int> t;
            t.push_back(x.first);
            t.push_back(x.second);
            ans.push_back(t);
            t.clear();
        }
        return ans;
    }
};