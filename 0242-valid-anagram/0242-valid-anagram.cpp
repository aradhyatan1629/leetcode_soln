class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> v(26,0);
        for(int i=0;i<s.size();i++)
            v[s[i]-'a']++;
        
        if(t.size()!=s.size())
            return false;
        for(int i=0;i<t.size();i++)
        {
            if(v[t[i]-'a']>0)
                v[t[i]-'a']--;
            else
                return false;
        }
        return true;
    }
};