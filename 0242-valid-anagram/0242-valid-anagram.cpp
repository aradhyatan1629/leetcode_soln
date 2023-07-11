class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
        {
            return false;
        }
        vector<int> v(26,0);
        for(int i=0;i<s.size();i++)
        {
            v[s[i]-'a']++;
        }
        for(int i=0;i<t.size();i++)
        {
            if(v[t[i]-'a']==0)
            {
                return false;
            }
            else
            {
                v[t[i]-'a']--;
            }
        }
        return true;
    }
};