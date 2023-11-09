class Solution {
public:
    int countHomogenous(string s) {
        int mod = 1e9+7;
        long long ans=0;
        long long cnt=1;
        for(int i=0;i<s.size()-1;i++)
        {
            if(s[i]==s[i+1])
            {
                cnt++;
            }
            else
            {
                ans+= (cnt*(cnt+1))/2;
                cnt=1;
            }
        }
        ans+= (cnt*(cnt+1))/2;
        return ans%mod;
    }
};