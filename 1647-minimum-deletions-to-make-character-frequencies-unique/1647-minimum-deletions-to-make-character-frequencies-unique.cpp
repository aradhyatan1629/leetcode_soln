class Solution {
public:
    int minDeletions(string s) {
        unordered_set<char> st;
        unordered_map<char,int> m;
        vector<pair<int,char>> v;
        int cnt=0;
        for(auto x:s)
        {
            m[x]++;
        }
        for(auto x:m)
        {
            v.push_back({x.second,x.first});
        }
        sort(v.begin(),v.end());
        int temp=-1;
        for(int i=v.size()-1;i>=0;i--)
        {
            while(st.find(v[i].first)!=st.end())
            {
                v[i].first--;
                if(v[i].first==0)
                {
                    cnt++;
                    temp=1;
                    st.insert(0);
                    break;
                }
                else
                {
                    cnt++;
                }
            }
            if(temp!=1)
            {
                st.insert(v[i].first);   
            }
        }
        return cnt;
    }
};