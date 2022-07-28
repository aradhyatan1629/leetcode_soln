class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> m1;
        unordered_map<char,int> m2;
        for(auto x:s)
        {
            m1[x]++;
        }
        for(auto x:t)
        {
            m2[x]++;
        }
        for(int i=0;i<t.size();i++)
        {
            if(m1.find(t[i])==m1.end())
            {
                return false;
            }
            if(m2[t[i]]>=m1[t[i]])
            {
                continue;
            }
            else
            {
                return false;
            }
        }
        if(s.size()>t.size())
        {
            return false;
        }
        return true;
    }
};