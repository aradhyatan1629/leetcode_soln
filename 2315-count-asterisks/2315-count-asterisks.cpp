class Solution {
public:
    int countAsterisks(string s) {
        bool flag=true;
        int cnt=0;
        for(int i=0;i<s.size();i++)
        {
            if(flag and s[i]=='*')
            {
                cnt++;
            }
            else if(s[i]=='|')
            {
                flag=!flag;
            }
        }
        return cnt;
    }
};