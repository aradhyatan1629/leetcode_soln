class Solution {
public:
    int secondHighest(string s) {
        int mx=INT_MIN;
        int ans=-1;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>=48 and s[i]<=57)
            {
                mx=max(mx,s[i]-'0');
            }
        }
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>=48 and s[i]<=57)
            {
                if(s[i]-'0'!=mx)
                {
                    ans=max(ans,s[i]-'0');
                }
            }
        }
        return ans;
    }
};