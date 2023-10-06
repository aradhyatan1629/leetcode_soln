class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int t=0;
        while(true)
        {
            bool flag = false;
            int i=1;
            while(i<s.size())
            {
                if(s[i-1]=='0' and s[i]=='1')
                {
                    s[i-1]='1';
                    s[i]='0';
                    flag=true;
                    i+=2;
                }
                else
                {
                    i++;
                }
            }
            if(flag==false)
            {
                break;
            }
            t++;
        }
        return t;
    }
};



