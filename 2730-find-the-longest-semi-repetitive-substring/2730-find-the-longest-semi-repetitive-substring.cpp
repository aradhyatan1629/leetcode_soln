class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int i=0,j=1,n=s.size();
        int len = 0,cnt=0;
        
        while(j<n)
        {
            if(s[j] != s[j-1])
            {
                j++;
            }
            else
            {
                cnt++;
                if(cnt==1)
                {
                    j++;
                }
                else
                {
                    j--;
                    len = max(len,j-i+1);
                    i++,j++;
                    while(s[i]!=s[i-1])
                    {
                        i++;
                    }
                    cnt=0;
                }
            }
            // cout<<i<<" "<<j<<endl;
        }
        len = max(len,j-i);
        return len;
    }
};