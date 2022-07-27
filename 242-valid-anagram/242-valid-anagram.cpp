class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> m1;
        unordered_map<char,int> m2;
        int i=0;
        for(auto x:s)
        {
            m1[x]++;
        }
        for(auto x:t)
        {
            m2[x]++;
        }
        for(i=0;i<s.size();i++)
        {
            if(m2.find(s[i])==m2.end())
            {
                return false;
            }
            else if(m2[s[i]]<m1[s[i]])
            {
                return false;
            }
        }
        if(m2.size()>m1.size())
        {
            return false;
        }
        return true;
    }
};