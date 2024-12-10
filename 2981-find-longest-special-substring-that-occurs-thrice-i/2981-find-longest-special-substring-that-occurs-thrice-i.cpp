class Solution {
public:
    int maximumLength(string s) {
        unordered_map<string,int> m;
        for(int i=0;i<s.size();i++)
        {
            string t;
            for(int j=i;j<s.size();j++)
            {
                t+=s[j];
                m[t]++;
            }
        }       

        int mx=-1;
        for(auto x:m)
        {
            if(x.second>=3)
            {
                unordered_set<char> st(x.first.begin(),x.first.end());
                if(st.size()==1)
                {
                    int t = x.first.size();
                    mx = max(mx,t);
                }
            }
        }
        return mx;
    }
};