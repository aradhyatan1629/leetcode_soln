class Solution {
public:
    string smallestString(string s) {
        int i=0;
        int cnt = count(s.begin(),s.end(),'a');
        if(cnt == s.size())
        {
            s[s.size()-1] = 'z';
            return s;
        }
        while(i<s.size() and s[i]=='a')
        {
            i++;
        }
        while(i<s.size() and s[i]!='a')
        {
            s[i] = (s[i]-1);
            i++;
        }
        return s;
    }
};