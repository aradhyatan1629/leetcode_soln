class Solution {
public:
    int numSub(string s) {
        long long int ans=0;
        long long int cnt=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='1')
            {
                cnt++;
            }
            else
            {
                ans+=(cnt*(cnt+1))/2;
                cnt=0;
            }
        }
        if(cnt!=0)
        {
            ans+=(cnt*(cnt+1))/2;
        }
        return ans%1000000007;
    }
};
/*
1 - 1
2 - 2+1
3 - 3+2+1
n - n+(n-1)+(n-2)+....+1 - sum of n natural nos. - (n*(n+1))/2
*/