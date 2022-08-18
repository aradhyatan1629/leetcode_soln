class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n=s.size();
        int l=-1;
        int ans=-1;
        for(int i=0;i<n;++i)
        {
            l=-1;
            for(int j=n-1;j>i;j--)
            {
                if(s[i]==s[j])
                {
                    l=j-i-1;
                    break;
                }
            }
            if(l>ans)
            {
                ans=l;
            }
        }
        return ans;
    }
};