class Solution {
public:
    int appendCharacters(string s, string t) {
        int i=0,j=0;
        int cnt = 0;
        while(i<s.size() && j<t.size())
        {
            if(s[i]==t[j])
                cnt++,j++;
            i++;
        }
        if(j==t.size())
            return 0;
        return t.size()-cnt;
    }
};