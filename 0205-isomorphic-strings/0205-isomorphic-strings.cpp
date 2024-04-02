class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,int> m;
        unordered_map<char,char> m1;
        for(int i=0;i<s.size();i++)
        {
            if(m.find(s[i])==m.end() and m1[t[i]]==1)
                return false;
            else if(m.find(s[i])==m.end() and  m1[t[i]]!=1)
                m[s[i]]=t[i], m1[t[i]]=1;
            else if(m.find(s[i])!=m.end() and m[s[i]]!=t[i])
                return false;
        }
        return true;
    }
};