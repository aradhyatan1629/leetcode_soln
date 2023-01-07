class Solution {
public:
    int countHomogenous(string s) {
        long long int cnt=0;
        long long int ans=0;
        int n=s.size();
        for(int i=0;i<s.size();i++)
        {
            char x=s[i];
            while(i<n and s[i]==x)
            {
                cnt++;
                i++;
            }
            i--;
            ans+=(cnt*(cnt+1))/2;
            cnt=0;
        }
        return ans%1000000007;
    }
};