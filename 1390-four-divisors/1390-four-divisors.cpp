class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        unordered_map<int,int> m;
        unordered_map<int,int> freq;
        for(auto x:nums)
        {
            m[x]=0;
        }
        for(auto x:nums)
        {
            freq[x]++;
        }
        for(auto x:m)
        {
            int t=x.first;
            int cnt=1;
            int sum=x.first;
            for(int i=1;i<=t/2;i++)
            {
                if(t%i==0)
                {
                    cnt++;
                    sum+=i;
                }
            }
            if(cnt==4)
            {
                m[x.first]=sum;
            }
        }
        int ans=0;
        for(auto x:freq)
        {
            if(m[x.first]!=0)
            {
                ans+=(m[x.first]*freq[x.first]);
            }
        }
        return ans;
    }
};