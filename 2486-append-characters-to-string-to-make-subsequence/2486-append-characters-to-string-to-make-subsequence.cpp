class Solution {
public:
    int appendCharacters(string s, string t) {
        int mx=0;
        int cnt=0;
        int j=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==t[j])
            {
                cnt++;
                j++;
            }
           /* else if(s[i]==t[0])
            {
                mx=max(mx,cnt);
                cnt=1;
            }*/
            else
            {
                mx=max(mx,cnt);
            }
        }
        mx=max(mx,cnt);
        return t.size()-mx;
    }
};