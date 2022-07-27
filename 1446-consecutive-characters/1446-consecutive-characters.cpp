class Solution {
public:
    int maxPower(string s) {
        int i=0,length=1,ans=1;
        for(i=1;i<s.size();i++)
        {
            if(s[i]==s[i-1])
            {
                ans = max(ans,++length);
            }
            else
            {
                length=1;
            }
        }
        return ans;
    }
};