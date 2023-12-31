class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> v(26,0);
        for(int i=0;i<s.size();i++)
        {
            v[s[i]-'a'] = i;
        }
        int mx=-1;
        for(int i=0;i<s.size();i++)
        {
            mx = max(mx,v[s[i]-'a']-i-1);
        }
        return mx;
    }
};