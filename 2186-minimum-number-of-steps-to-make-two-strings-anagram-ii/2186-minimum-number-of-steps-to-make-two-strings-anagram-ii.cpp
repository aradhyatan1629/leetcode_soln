class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int> m1;
        unordered_map<char,int> m2;
        int cnt=0;
        for(auto x:s)
        {
            m1[x]++;
        }
        for(auto x:t)
        {
            m2[x]++;
        }
        for(int i=0;i<s.size();++i)
        {
            if(m1[s[i]]>m2[s[i]])
            {
                t.push_back(s[i]);
                m2[s[i]]++;
                cnt++;
            }
        }
        for(int i=0;i<t.size();++i)
        {
            if(m2[t[i]]>m1[t[i]])
            {
                s.push_back(t[i]);
                m1[t[i]]++;
                cnt++;
            }
        }
        return cnt;
    }
};

